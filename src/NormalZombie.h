//
// Created by yb on 2024/5/10.
//

#ifndef PVZ_NORMALZOMBIE_H
#define PVZ_NORMALZOMBIE_H
#include "Zombie.h"

class NormalZombie :public Zombie{//∆’Õ®Ω© ¨
public:
    NormalZombie();
    ~NormalZombie() override =default;
public:
    ZombieType getType() override;
public:
    static ZombieType s_type;
};


#endif //PVZ_NORMALZOMBIE_H
