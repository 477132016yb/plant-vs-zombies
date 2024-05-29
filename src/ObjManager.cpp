//
// Created by yb on 2024/5/7.
//

#include "ObjManager.h"
#include "ClassFactory.h"
extern std::vector<int> g_selectNum;
ClassFactory* g_factory=Singleton<ClassFactory>::instance();
ObjManager::ObjManager() {
    m_sun= 1500;
    m_cur= nullptr;
    m_isMove=false;
}

void ObjManager::init() {
    srand(time(nullptr));
    auto r=Singleton<res>::instanceSP();

    m_cardCoolAtion.resize(g_selectNum.size());
    for (int i = 0; i < g_selectNum.size(); i++) {
        if (g_selectNum[i] == -1) {
            m_cardCoolAtion.resize(i); break;
        }
    }
    Atlas::SP atlas=std::make_shared<Atlas>(r->atl_cardCoolTime);
    for(int i=0;i<m_cardCoolAtion.size();i++){
        m_cardCoolAtion[i]=std::make_shared<Animation>();
        m_cardCoolAtion[i]->setAtlas(atlas);
        m_cardCoolAtion[i]->setInterval(yb::plantCoolTimeList[g_selectNum[i]]);
        m_cardCoolAtion[i]->setLoop(false);
    }

    m_shovelObj = dynamic_cast<StaticObj*>(g_factory->create_class("StaticObj"));
    m_virtualPlant = dynamic_cast<StaticObj*>(g_factory->create_class("StaticObj"));
    m_shovelObj->setImage(&r->img_shovel);
    m_shovelObj->m_x=760,m_shovelObj->m_y=-10;
    m_car.resize(5);
    for(int i=0;i<m_car.size();i++){
        m_car[i]=dynamic_cast<StaticObj*>(g_factory->create_class("Car"));
        m_car[i]->m_y = 120 + i * 97;
        m_car[i]->m_x = 70;
        m_car[i]->m_row = i;
        m_car[i]->setImage(&r->img_car);
    }

    m_plantMap = std::vector<std::vector<Object*>>(5, std::vector<Object*>(10,nullptr));
    m_zombiePool = std::vector<std::vector<Object*>>(5);
}

void ObjManager::update(int delta) {
    creatObject(delta);
    for(auto&a:m_plantMap){
        yb::updateVector(a,delta);
    }
    for(auto&a:m_zombiePool){
        yb::updateVector(a,delta);
    }
    yb::updateVector(m_sunShinePool,delta);
    yb::updateVector(m_bulletPool,delta);
    yb::updateVector(m_car,delta);
    for(auto&a:m_cardCoolAtion){a->update(delta);}
    processCollide();
    updateMemory();
}

void ObjManager::draw() {
    auto r=Singleton<res>::instanceSP();
    putimage(-112,0,&r->img_bg);
    putimage(250 - 112,0,&r->img_gameBar);
    putimagePNG(750,0,&r->img_shovelSlot);
    m_shovelObj->draw();
    if(m_isMove){
        m_virtualPlant->draw();
    }

    char sun[8];
    sprintf_s(sun, sizeof(sun), "%d", m_sun);
    outtextxy(278-112, 69, sun);

    for(int i=0;i<g_selectNum.size();i++){
        if(g_selectNum[i]==-1){break;}
        int num=g_selectNum[i];
        int x=339 - 112+i*(r->imgs_gameCard[num].getwidth()+5);
        int y=8;
        putimage(x,y,&r->imgs_gameCard[num]);
        if(m_sun<yb::plantCostList[g_selectNum[i]]){
            putimagePNG(x,y,&r->img_gameCardMask);
        }
        m_cardCoolAtion[i]->draw(x,y);
    }
    for(auto&a:m_plantMap){
        yb::drawVector(a);
    }
    for(auto&a:m_zombiePool){
        yb::drawVector(a);
    }
    if(m_cur){
        m_cur->draw();
    }
    yb::drawVector(m_sunShinePool);
    yb::drawVector(m_bulletPool);
    yb::drawVector(m_car);
}

void ObjManager::input(const ExMessage &msg) {
    switch (msg.message) {
        case WM_LBUTTONDOWN:
            processLeftButton(msg);
            m_isMove=false;
            break;
        case WM_MOUSEMOVE:
        {
            if(m_cur){
                m_cur->m_x=msg.x-20;
                m_cur->m_y=msg.y-20;
                if(m_cur->getName()!="StaticObj"){
                    m_isMove=true;
                }
            }
            int x = msg.x;
            int y = msg.y;
            if (x > 144 && y > 77 && y < 591) {
                int row = (y - 77) / 102;
                int col = (x - 144) / 81;
                m_virtualPlant->m_y = 77 + row * 102;
                m_virtualPlant->m_x = 144 + col * 81;
            }
        }
            break;
        case WM_RBUTTONDOWN:
            if(m_cur){
                if(m_cur->getName()=="StaticObj"){
                    m_shovelObj->m_x=760,m_shovelObj->m_y=-10;
                }
                else{
                    delete m_cur;
                }
                m_cur = nullptr;
                m_virtualPlant->m_isDraw=false;
            }
            break;
        case WM_LBUTTONUP:
            break;
        default:
            break;
    }
}

void ObjManager::checkSunShine(const ExMessage &msg) {
    for(auto&a:m_sunShinePool){
        if(!a){ continue;}
        if(yb::checkHit(msg.x,msg.y,a->m_x+5,a->m_y+5,60,60)){
            a->collect();
            m_sun+=25;
            PlaySound(TEXT("res/music/sunshine.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
}

void ObjManager::updateMemory() {
    yb::clearVector(m_sunShinePool);
    yb::clearVector(m_bulletPool);
    for(auto&a:m_zombiePool){
        yb::clearVector(a);
    }
    for(auto&a:m_plantMap){
        for(auto&b:a){
            if(b&&!b->m_used){
                delete b;
                b = nullptr;
            }
        }
    }
    for(auto&a:m_car){
        if(a&&!a->m_used){
            delete a;
            a= nullptr;
        }
    }
}

void ObjManager::creatObject(int delta) {
    creatSunShine(delta);
    creatZombie(delta);
}

void ObjManager::creatSunShine(int delta) {
    static int count = 0;
    count += delta;
    static int fre = 10;
    if (count <=fre) {return;}
    count = 0;
    fre = 3000 + rand() % 2000;

    auto a =g_factory->create_class("SunShine");
    m_sunShinePool.push_back(a);
}

std::vector<Object *> &ObjManager::getSunShineVec() {
    return m_sunShinePool;
}

ObjManager::~ObjManager() {
    delete m_shovelObj;
    delete m_virtualPlant;
}

void ObjManager::processLeftButton(const ExMessage &msg) {
    static int idx = -1;
    if (!m_cur&&msg.x > 227 && msg.x < 227 + 64 * g_selectNum.size() && msg.y < 96 && msg.y>8) {
        idx = (msg.x - (227)) / 64;
        if (g_selectNum[idx] == -1) {
            return;
        }
        if(m_sun<yb::plantCostList[g_selectNum[idx]]||!m_cardCoolAtion[idx]->checkFinished()){ return;}
        m_cur = g_factory->create_class(yb::plantNameList[g_selectNum[idx]]);
        m_virtualPlant->setImage(&Singleton<res>::instanceSP()->imgs_vriPlantVec[g_selectNum[idx]]);
        m_virtualPlant->m_isDraw=true;
    }
    else if (msg.x>750&&msg.x<750+70&&msg.y<70&&msg.y>10) {
        m_cur=m_shovelObj;
        idx=-1;
    }
    else if(m_cur){
        int x = msg.x;
        int y = msg.y;
        if (x > 144 && y > 77 && y < 591) {
            int row = (y - 77) / 102;
            int col = (x - 144) / 81;
            if (m_cur&&(!m_plantMap[row][col])&&idx!=-1) {//植物种下
                m_cur->m_y = 77 + row * 102+m_cur->m_dy;
                m_cur->m_x = 144 + col * 81+m_cur->m_dx;;
                m_cur->m_row=row;
                m_cur->m_col=col;
                m_plantMap[row][col] = m_cur;
                m_sun-=yb::plantCostList[idx];
                m_cardCoolAtion[idx]->reset();
                m_cur= nullptr;
                idx=-1;
                PlaySound(TEXT("res/music/plant1.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if(m_cur&&m_plantMap[row][col]&&m_cur->getName()=="StaticObj"){//铲子按下
                m_plantMap[row][col]->m_used=false;
                m_cur = nullptr;
                m_shovelObj->m_x=760,m_shovelObj->m_y=-10;
                PlaySound(TEXT("res/music/plant2.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
        }
    }
    else{
        checkSunShine(msg);
    };
}

std::vector<Object *> &ObjManager::getBulletVec() {
    return m_bulletPool;
}

void ObjManager::creatZombie(int delta) {
    static int count = 0;
    count += delta;
    static int fre = 10;
    if (count <=fre) {return;}
    count = 0;
    fre = 8000 + rand() % 5000;
    auto a = g_factory->create_class(yb::zombieNameList[rand() % 4]);
    m_zombiePool[a->m_row].push_back(a);
}

std::vector<Object *> &ObjManager::getZombies(int row) {
    return m_zombiePool[row];
}

void ObjManager::processCollide() {
    for(auto&a:m_bulletPool){
        int row=a->m_row;
        std::vector<Object*>&vec=m_zombiePool[row];
        if(vec.empty()){ continue;}
        for(auto&b:vec){
            a->collide(b);
        }
    }
    for(int i=0;i<5;i++){
        auto&a=m_zombiePool[i];
        auto&b=m_plantMap[i];
        collideVec(a,b);
        collideVec(b,a);

        for(auto&c:a){
            if(m_car[i]){
                m_car[i]->collide(c);
            }
        }
    }
}

void ObjManager::collideVec(std::vector<Object *> &v1, std::vector<Object *> &v2) {
    for(auto&a:v1){
        if(!a){continue;}
        for(auto&b:v2){
            if(!b){continue;}
            a->collide(b);
        }
    }
}

