#pragma once
#include "plant.h"
class YTZD :
    public plant
{
public:
    YTZD();
    int img_boom_indx;
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};

