#pragma once
#include "plant.h"
//º®±ùÉäÊÖ
class HBSS :
    public plant
{
public:
    HBSS();
    int count;
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};

