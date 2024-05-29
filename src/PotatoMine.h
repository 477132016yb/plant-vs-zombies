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
    Timer m_timer;//�ӵص�����ͱ�ը��������ʱ�䶨ʱ��
    PotatoMineStatus m_status;//��������״̬
    int m_damage;
};


#endif //PVZ_POTATOMINE_H
