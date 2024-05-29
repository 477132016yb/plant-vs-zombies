//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_GAMESCENE_H
#define PVZ_GAMESCENE_H
#include "Scene.h"
#include "SceneManager.h"
#include "ObjManager.h"
class GameScene :public Scene{//”Œœ∑≥°æ∞
public:
    GameScene();
    ~GameScene()=default;
public:
    void on_enter() override;
    void on_update(int delta) override;
    void on_draw() override;
    void on_input(const ExMessage& msg) override;
    void on_exit() override;
private:
    ObjManager::SP m_objManager;
};

#endif //PVZ_GAMESCENE_H
