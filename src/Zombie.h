//
// Created by yb on 2024/5/10.
//

#ifndef PVZ_ZOMBIE_H
#define PVZ_ZOMBIE_H

#include "ClassFactory.h"
#include "Animation.h"
#include "res.h"
class Zombie :public Object{//僵尸基类
public:
    Zombie();
    ~Zombie() override = default;
public:
    enum class ZombieType{//僵尸类型
        NormalZombie,
        RoadBlockZombie,
        BucketZombie,
        FootballZombie
    };
    enum class ZombieStatus{//僵尸状态
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
    void setStatus(ZombieStatus status);//设置状态
    virtual ZombieType getType() { return ZombieType::NormalZombie; }
protected:
    int m_isArmor;//是否有防具
    Timer t_sketch,t_cool;//冰冻效果和打击效果定时器
    int m_speed;//移动速度
    int m_timer;//控制僵尸整体刷新帧率
    int m_damage;//伤害
    ZombieStatus m_status;//状态
    Animation::SP m_action;//动画
    Animation::SP m_headAction;//掉头动画

    std::vector<Atlas::SP> m_atls;//动画所需图集数组
};


#endif //PVZ_ZOMBIE_H
