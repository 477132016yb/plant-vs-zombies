//
// Created by yb on 2024/5/24.
//

#ifndef PVZ_ROADBLOCKZOMBIE_H
#define PVZ_ROADBLOCKZOMBIE_H

#include "Zombie.h"
class RoadBlockZombie: public Zombie{
public:
    RoadBlockZombie();
    ~RoadBlockZombie() override =default;
public:
    void update(int delta) override;
public:
    ZombieType getType() override;
public:
    static ZombieType s_type;
};


#endif //PVZ_ROADBLOCKZOMBIE_H
