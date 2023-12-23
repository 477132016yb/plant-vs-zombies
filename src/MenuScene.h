//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_MENUSCENE_H
#define PVZ_MENUSCENE_H
#include "Scene.h"
#include "SceneManager.h"
class MenuScene :public Scene{//²Ëµ¥³¡¾°
public:
    MenuScene();
    ~MenuScene()=default;
public:
    void on_enter() override ;
    void on_update(int delta) override ;
    void on_draw() override;
    void on_input(const ExMessage& msg)override;
    void on_exit()override;
private:
    Button::SP m_startButton;
    IMAGE *m_menu;
};


#endif //PVZ_MENUSCENE_H
