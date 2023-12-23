//
// Created by yb on 2024/4/28.
//

#ifndef PVZ_PLANT_H
#define PVZ_PLANT_H

#include "ClassFactory.h"
#include "Animation.h"
#include "res.h"

class plant :public Object {
public:
    enum class plantType{//植物种类
        PeaShooter,
        SunFlower,
        SnowPea,
        NutWall,
        PotatoMine,
        Chomper,
        TorchWood,
        CherryBomb,
        None
    };
public:
    plant();
    ~plant() override =default;
    void update(int delta) override;
    void draw() override;
    virtual void skills(int delta){};//植物技能
public:
    virtual plantType getType()=0;
protected:
    Animation::SP m_action;//动画
    int m_skillTime;//技能冷却时间
};

#endif //PVZ_PLANT_H
