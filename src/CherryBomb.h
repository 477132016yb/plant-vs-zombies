//
// Created by yb on 2024/5/24.
//

#ifndef PVZ_CHERRYBOMB_H
#define PVZ_CHERRYBOMB_H

#include "plant.h"
class CherryBomb :public plant{
public:
    CherryBomb();
public:
    plantType getType() override;
    void skills(int delta)override;
private:
    void Boom();
private:
    static plantType s_type;
    int m_damage;
};


#endif //PVZ_CHERRYBOMB_H
