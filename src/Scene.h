//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_SCENE_H
#define PVZ_SCENE_H

#include<windows.h>
#include<mmsystem.h>
#include "graphics.h"
#include "const.h"
#include "Singleton.h"
#include "Button.h"
#include "res.h"
#pragma comment(lib, "winmm.lib")

class Scene {//³¡¾°»ùÀà
public:
    Scene()=default;
    ~Scene()=default;
public:
    virtual void on_enter()=0;
    virtual void on_update(int delta)=0;
    virtual void on_draw()=0;
    virtual void on_input(const ExMessage& msg)=0;
    virtual void on_exit()=0;
};


#endif //PVZ_SCENE_H
