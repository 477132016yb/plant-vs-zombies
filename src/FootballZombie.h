//
// Created by yb on 2024/5/24.
//

#ifndef PVZ_FOOTBALLZOMBIE_H
#define PVZ_FOOTBALLZOMBIE_H
#include "Zombie.h"

class FootballZombie :public Zombie{
public:
    FootballZombie();
    ~FootballZombie() override =default;
public:
    ZombieType getType() override;
public:
    static ZombieType s_type;
};


#endif //PVZ_FOOTBALLZOMBIE_H
