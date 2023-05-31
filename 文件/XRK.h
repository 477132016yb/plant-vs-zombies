#pragma once
#include "plant.h"
//ÏòÈÕ¿û
class XRK :
    public plant
{
public:
    XRK();
    int time;
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};