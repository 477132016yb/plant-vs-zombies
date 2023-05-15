#pragma once
#include "plant.h"
class JGQ :
    public plant
{
public:
    JGQ();
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball) {};
};

