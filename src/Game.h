//
// Created by yb on 2024/4/29.
//

#ifndef PVZ_GAME_H
#define PVZ_GAME_H
#include "res.h"
#include "Singleton.h"
#include "tools.h"
#include "const.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "SelectScene.h"
class Game {
public:
    Game();
    void init();
    void play();
private:
    res::SP m_r;
    SceneManager*m_sceneManager;
};


#endif //PVZ_GAME_H
