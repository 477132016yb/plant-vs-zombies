#pragma once
#include "plant.h"
// ≥»Àª®
class SRH :
    public plant
{
public:
    SRH();
    int status;
    int wait;
    virtual void update();
    virtual void jineng(vector<bullet>& bullets, vector<zm*>&zms, vector<sunshine>& ball);
};

