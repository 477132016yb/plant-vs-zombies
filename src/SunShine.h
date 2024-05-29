//
// Created by yb on 2024/5/5.
//

#ifndef PVZ2_SUNSHINE_H
#define PVZ2_SUNSHINE_H

#include "Object.h"
#include "vector2.h"
#include "Animation.h"
#include "res.h"
class SunShine :public Object{
public:
    SunShine();
    ~SunShine() override =default;
public:
    enum class SunStatus{
        SUNSHINE_COLLECT,
        SUNSHINE_DOWN,
        SUNSHINE_GROUND,
        SUNSHINE_PRODUCT
    };
public:
    static  SunShine* creatSunShine(int x,int y);
    void collect() override;
public:
    int m_timer=0;
    float m_t;
    vector2 p1, p2, p3, p4;
    vector2 m_curp;
    float m_speed;
    SunStatus m_status;
    Animation::SP m_action;
public:
    void draw() override;
    void update(int delta) override;
};


#endif //PVZ2_SUNSHINE_H
