//
// Created by yb on 2024/5/2.
//

#ifndef PVZ_SELECTSCENE_H
#define PVZ_SELECTSCENE_H
#include "Scene.h"
#include "res.h"
#include "Camera.h"
#include "SceneManager.h"

class SelectScene :public Scene{//Ñ¡¿¨³¡¾°
public:
    SelectScene();
    ~SelectScene()=default;
public:
    void on_enter() override;
    void on_update(int delta) override;
    void on_draw() override;
    void on_input(const ExMessage& msg) override;
    void on_exit() override;
private:
    Camera::SP m_camera;
    Button::SP m_fightButton;
    std::vector<bool>m_isCardSelect;
    int m_cardWidth,m_cardHeight;
};


#endif //PVZ_SELECTSCENE_H
