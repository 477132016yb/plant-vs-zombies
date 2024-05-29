//
// Created by yb on 2024/5/13.
//

#ifndef PVZ_CHOMPER_H
#define PVZ_CHOMPER_H

#include "plant.h"
class Chomper :public plant{//ʳ�˻�
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
    void setStatus(ChomperStatus status);//״̬�л�
private:
    static plantType s_type;
    ChomperStatus m_status;//ʳ�˻�״̬
    Timer m_timer;//����ʱ��ʱ��
    int m_damage;//�˺�
    Object*m_temp;//��ʱ��ʬ����ָ��
};


#endif //PVZ_CHOMPER_H
