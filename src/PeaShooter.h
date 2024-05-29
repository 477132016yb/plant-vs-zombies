//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_PEASHOOTER_H
#define PVZ_PEASHOOTER_H
#include "plant.h"
class PeaShooter :public plant{
public:
    PeaShooter();
public:
    plantType getType() override;
    void skills(int delta)override;
private:
    static plantType s_type;
    int m_creatSpeed;
};

#endif //PVZ_PEASHOOTER_H
