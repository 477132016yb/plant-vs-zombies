//
// Created by yb on 2024/5/2.
//

#include "SelectScene.h"
#include "ClassFactory.h"
extern std::vector<int> g_selectNum;
SelectScene::SelectScene() {
    auto r=Singleton<res>::instanceSP();
    m_camera=Singleton<Camera>::instanceSP();
    m_fightButton=std::make_shared<Button>();
    m_cardWidth=50;
    m_cardHeight=72;
    m_isCardSelect.resize(r->imgs_selectCard.size());

    m_fightButton->setRect({155,545,150+150,550+40});
    m_fightButton->setImage(r->imgs_fightButton);
    m_fightButton->setCallback([this](){
        mciSendString("play res/music/seedlift.mp3", 0, 0, 0);
        m_camera->reSetSpeed(-0.2);
        m_camera->setWaitTime(1940);   //500-112=388  388/0.2=1940
        m_camera->timerReSet();
        m_camera->setCallback([](){
            Singleton<SceneManager>::instance()->switchTo(SceneManager::SceneType::Game);
        });
    });
}

void SelectScene::on_enter() {
    LOG("进入选择场景");
    m_fightButton->reSet();
}

void SelectScene::on_update(int delta) {
    m_camera->update(delta);
}

void SelectScene::on_draw() {
    auto r=Singleton<res>::instanceSP();
    putimage(0-m_camera->getPosition().x,0-m_camera->getPosition().y,&r->img_bg);
    if(m_camera->isTrigger()){
        int objY=r->img_selectBar.getheight();
        putimage(0,0,&r->img_selectBar);
        putimage(0,objY,&r->img_PanelBackGround);
        m_fightButton->draw();

        for(int i=0;i<r->imgs_selectCard.size();i++){
            int row=i/8,col=i%8;
            int x=25+col*(m_cardWidth+2);
            int y=objY+40+row*(m_cardHeight+1);
            putimage(x,y,&r->imgs_selectCard[i]);
            if(m_isCardSelect[i]){
                putimagePNG(x,y,&r->img_selectCardMask);
            }
        }

        for(int i=0;i<g_selectNum.size();i++){
            if(g_selectNum[i]==-1){break;}
            int num=g_selectNum[i];
            int x=78+i*(m_cardWidth+5);
            int y=5;
            putimage(x,y,&r->imgs_selectCard[num]);
        }
    }
}

void SelectScene::on_input(const ExMessage &msg) {
    m_fightButton->processEvent(msg);
    static int num=-1,idx=-1;
    switch (msg.message) {
        case WM_LBUTTONDOWN:
            if (msg.x > 78 && msg.x < 78 + 55 * (g_selectNum.size()) && msg.y < 5+m_cardHeight && msg.y>5) {
                idx = (msg.x - 78) / 55;
            }
            else if (msg.x > 25 && msg.x < 24 + 52 * 8 && msg.y < 76*2+131 && msg.y>131) {
                num = (msg.x - 25) / 52 + ((msg.y - 131) / 76)*8;
            }
            break;
        case WM_LBUTTONUP:
            if (idx != -1) {
                if(g_selectNum[idx]==-1){
                    break;
                }
                m_isCardSelect[g_selectNum[idx]]=false;
                for(int i=idx;i<g_selectNum.size()-1;i++){
                    g_selectNum[i]=g_selectNum[i+1];
                }
                g_selectNum.back()=-1;
                idx = -1;
            }
            if (num != -1) {
                if(m_isCardSelect[num]){
                    break;
                }
                for (int i = 0; i < g_selectNum.size();i++) {
                    if(g_selectNum[i]==-1){
                        g_selectNum[i]=num;
                        m_isCardSelect[num]=true;
                        break;
                    }
                }
                num = -1;
            }
            break;
        default:
            break;
    }
}

void SelectScene::on_exit() {
    LOG("离开选择场景");
}
