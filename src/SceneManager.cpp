//
// Created by yb on 2024/4/30.
//

#include "SceneManager.h"
std::vector<int> g_selectNum=std::vector<int>(8,-1);
//std::vector<int> g_selectNum=std::vector<int>{0,1,2,3,4,5,6,7};
void SceneManager::setCurrentState(Scene *scene) {
    m_scene=scene;
    m_scene->on_enter();
}

void SceneManager::switchTo(SceneManager::SceneType type) {
    m_scene->on_exit();
    switch (type) {
        case SceneType::Game:
            m_scene=g_gameSence;
            break;
        case SceneType::Menu:
            m_scene=g_menuSence;
            break;
        case SceneType::Select:
            m_scene=g_selectSence;
        default:
            break;
    }
    m_scene->on_enter();
}

void SceneManager::input(ExMessage &msg) {
    m_scene->on_input(msg);
}

void SceneManager::draw() {
    m_scene->on_draw();
}

void SceneManager::update(int delta) {
    m_scene->on_update(delta);
}
