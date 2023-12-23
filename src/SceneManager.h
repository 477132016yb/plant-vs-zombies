//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_SCENEMANAGER_H
#define PVZ_SCENEMANAGER_H
#include "Scene.h"
extern Scene* g_gameSence;
extern Scene* g_menuSence;
extern Scene* g_selectSence;
class SceneManager {//场景管理者
public:
    enum class SceneType{
        Menu,
        Game,
        Select
    };
public:
    SceneManager()=default;
    ~SceneManager()=default;
public:
    void setCurrentState(Scene*scene);
    void switchTo(SceneType type);
    void input(ExMessage&msg);
    void update(int delta);
    void draw();
private:
    Scene*m_scene = nullptr;
};


#endif //PVZ_SCENEMANAGER_H
