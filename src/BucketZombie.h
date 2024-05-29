//
// Created by yb on 2024/5/24.
//

#ifndef PVZ_BUCKETZOMBIE_H
#define PVZ_BUCKETZOMBIE_H

#include "Zombie.h"
class BucketZombie :public Zombie{
public:
    BucketZombie();
    ~BucketZombie() override =default;
public:
    void update(int delta) override;
    ZombieType getType() override;
public:
    static ZombieType s_type;
};


#endif //PVZ_BUCKETZOMBIE_H
