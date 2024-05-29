//
// Created by yb on 2024/4/30.
//

#include "GameScene.h"
#include "PlantHeadFile.h"
#include "ZombieHeadFile.h"
void GameScene::on_draw() {
    m_objManager->draw();
}

void GameScene::on_enter() {
    LOG("进入游戏内场景");
    m_objManager->init();
    mciSendString("stop res/music/bg.mp3", 0, 0, 0);
    mciSendString("play res/music/UraniwaNi.mp3 repeat", 0, 0, 0);
}

void GameScene::on_update(int delta) {
    m_objManager->update(delta);
}

void GameScene::on_input(const ExMessage &msg) {
    m_objManager->input(msg);
}

void GameScene::on_exit() {
    LOG("游戏局内退出");
    mciSendString("stop res/music/UraniwaNi.mp3 repeat", 0, 0, 0);
}

GameScene::GameScene() {
    m_objManager=Singleton<ObjManager>::instanceSP();
}

