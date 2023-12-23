//
// Created by yb on 2024/5/12.
//
#include "plant.h"
#ifndef PVZ_POTATOMINE_H
#define PVZ_POTATOMINE_H

class PotatoMine :public plant{
public:
    PotatoMine();
public:
    enum class PotatoMineStatus{
        UnderGround,
        Normal,
        Boom
    };
public:
    plantType getType() override;
    void skills(int delta)override;
    void draw()override;
    void collide(Object*obj)override;
private:
    static plantType s_type;
    Timer m_timer;//从地底钻出和爆炸动画持续时间定时器
    PotatoMineStatus m_status;//土豆地雷状态
    int m_damage;
};


#endif //PVZ_POTATOMINE_H
