#pragma once
#include "plant.h"
//�㶹����
class WDSS :
    public plant
{
public:
    WDSS();
    int count;
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};

