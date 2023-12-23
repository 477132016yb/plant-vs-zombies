//
// Created by yb on 2024/5/13.
//

#ifndef PVZ_CHOMPER_H
#define PVZ_CHOMPER_H

#include "plant.h"
class Chomper :public plant{//食人花
public:
    Chomper();
public:
    enum class ChomperStatus{
        Normal,
        Attack,
        Digestion
    };
public:
    plantType getType() override;
    void collide(Object*obj)override;
    void skills(int delta)override;
private:
    void setStatus(ChomperStatus status);//状态切换
private:
    static plantType s_type;
    ChomperStatus m_status;//食人花状态
    Timer m_timer;//消化时定时器
    int m_damage;//伤害
    Object*m_temp;//临时僵尸对象指针
};


#endif //PVZ_CHOMPER_H
