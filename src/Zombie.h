//
// Created by yb on 2024/5/10.
//

#ifndef PVZ_ZOMBIE_H
#define PVZ_ZOMBIE_H

#include "ClassFactory.h"
#include "Animation.h"
#include "res.h"
class Zombie :public Object{//��ʬ����
public:
    Zombie();
    ~Zombie() override = default;
public:
    enum class ZombieType{//��ʬ����
        NormalZombie,
        RoadBlockZombie,
        BucketZombie,
        FootballZombie
    };
    enum class ZombieStatus{//��ʬ״̬
        Stand,
        Walking,
        Attack,
        FallDown,
        Ashes,
        None
    };
public:
    void update(int delta) override;
    void draw() override;
    void collide(Object*obj) override;
    void setEffect(int type) override;
public:
    void setStatus(ZombieStatus status);//����״̬
    virtual ZombieType getType() { return ZombieType::NormalZombie; }
protected:
    int m_isArmor;//�Ƿ��з���
    Timer t_sketch,t_cool;//����Ч���ʹ��Ч����ʱ��
    int m_speed;//�ƶ��ٶ�
    int m_timer;//���ƽ�ʬ����ˢ��֡��
    int m_damage;//�˺�
    ZombieStatus m_status;//״̬
    Animation::SP m_action;//����
    Animation::SP m_headAction;//��ͷ����

    std::vector<Atlas::SP> m_atls;//��������ͼ������
};


#endif //PVZ_ZOMBIE_H
