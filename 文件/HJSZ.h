#pragma once
#include "plant.h"
//»ð¾æÊ÷×®
class HJSZ :
    public plant
{
public:
    HJSZ();
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};

