//
// Created by yb on 2024/5/10.
//

#include"Zombie.h"
Zombie::Zombie() {
    m_isArmor=false;
    m_action = std::make_shared<Animation>();
    m_headAction = std::make_shared<Animation>();
    m_atls.resize(5);
    m_speed=2;
    m_timer=0;
    m_x = 850+ rand() % 100;
    m_row = 3+rand() % 2;
    m_y = 30 + 100 * m_row;
    m_damage=20;

    t_sketch.setCallback([this](){
        m_action->setSketch(false);
    });
    t_sketch.setOneTrigger(false);
    t_sketch.setWaitTime(100);

    t_cool.setCallback([this](){
        m_action->setCool(false);
    });
    t_cool.setOneTrigger(false);
    t_cool.setWaitTime(3000);

    //…Ë÷√µÙÕ∑∂Øª≠
    auto r=Singleton<res>::instanceSP();
    auto atlas=std::make_shared<Atlas>(r->atl_zombieHead);
    m_headAction->setAtlas(atlas);
    m_headAction->setLoop(false);
    m_headAction->setInterval(10);
    m_headAction->setCallback([this](){
        m_used=false;
    });
}

void Zombie::draw() {
    m_action->draw(m_x,m_y);
    if(m_status==ZombieStatus::FallDown){
        m_headAction->draw(m_x+15,m_y+5);
    }
}

void Zombie::update(int delta) {
    m_action->update(delta);
    m_timer+=delta;

    if(m_action->getSketch()){
        t_sketch.update(delta);
    }
    if(m_action->getCool()){
        t_cool.update(delta);
    }
    int t=m_action->getCool()?240:120;
    if(m_timer<t){return;}
    m_timer=0;
    m_col = ((m_x - 144) / 81) + 1;
    if(m_blood<0&&m_blood>-30&&m_status!=ZombieStatus::FallDown){
        setStatus(ZombieStatus::FallDown);
        m_action->setLoop(false);
        m_action->setCallback([this](){
            m_isCollide=false;
        });
    }
    else if(m_blood<-1000&&m_status!=ZombieStatus::Ashes){
        m_isCollide=false;
        setStatus(ZombieStatus::Ashes);
        m_action->setLoop(false);
        m_action->setCallback([this](){
            m_used=false;
        });
    }
    switch (m_status) {
        case ZombieStatus::Stand:
            break;
        case ZombieStatus::Walking:
            m_x-=m_speed;
            if(m_x<0){
                m_used=false;
            }
            break;
        case ZombieStatus::Attack:
            break;
        case ZombieStatus::FallDown:
            m_headAction->update(delta);
            break;
        case ZombieStatus::Ashes:
            break;
        default:
            break;
    }
}

void Zombie::collide(Object *obj) {
    static int count=0;
    if(!obj->m_isCollide){return;}
    if(m_status!=ZombieStatus::Attack&&m_status!=ZombieStatus::Walking){return;}
    if(yb::checkHitX(m_x,obj->m_x-50,30)){
        if(m_status==ZombieStatus::Walking){
            setStatus(ZombieStatus::Attack);
        }
        count++;
        mciSendString("play res/music/chompsoft.mp3", 0, 0, 0);
        if(count>30){
            count=0;
            obj->m_blood-=m_damage;
            mciSendString("play res/music/chomp.mp3", 0, 0, 0);
        }
        if(!obj->m_used){
            setStatus(ZombieStatus::Walking);
        }
    }
}

void Zombie::setStatus(Zombie::ZombieStatus status) {
    m_status=status;
    m_action->reset();
    m_action->setAtlas(m_atls[int(m_status)]);
}

void Zombie::setEffect(int type) {
    if(getType()==ZombieType::BucketZombie){
        PlaySound(TEXT("res/music/shieldhit.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else{
        PlaySound(TEXT("res/music/splat2.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    if(type==0){
        m_action->setSketch(true);
    }
    else if(type==1){
        if(!m_action->getCool()){
            m_action->setCool(true);
            mciSendString("play res/music/frozen.mp3", 0, 0, 0);
        }
        t_cool.restart();
    }
}
