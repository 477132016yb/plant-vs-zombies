#pragma once
#include "plant.h"
//¼á¹ûÇ½
class JGQ :
    public plant
{
public:
    JGQ();
    int status;
    virtual void update();
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball) {};
};

