#pragma once
#include "plant.h"
//���ǽ
class JGQ :
    public plant
{
public:
    JGQ();
    int status;
    virtual void update();
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball) {};
};

