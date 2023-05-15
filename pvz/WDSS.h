#pragma once
#include "plant.h"
class WDSS :
    public plant
{
public:
    WDSS();
    int timer;
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};

