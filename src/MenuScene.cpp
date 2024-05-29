//
// Created by yb on 2024/4/30.
//

#include "MenuScene.h"
void MenuScene::on_enter() {
    LOG("进入主菜单");
    m_startButton->reSet();
    mciSendString("play res/music/bg.mp3", 0, 0, 0);
}

void MenuScene::on_update(int delta) {

}

void MenuScene::on_draw() {
    putimage(0,0,m_menu);
    m_startButton->draw();
}

void MenuScene::on_input(const ExMessage &msg) {
    m_startButton->processEvent(msg);
}

void MenuScene::on_exit() {
    LOG("主菜单退出");
}

MenuScene::MenuScene() {
    res::SP r=Singleton<res>::instanceSP();
    m_menu=&r->img_menu;
    m_startButton=std::make_shared<Button>();

    m_startButton->setRect({475,80,475+330,80+150});
    m_startButton->setImage(r->imgs_startButton);
    m_startButton->setCallback([](){
        Singleton<SceneManager>::instance()->switchTo(SceneManager::SceneType::Select);
    });
}
