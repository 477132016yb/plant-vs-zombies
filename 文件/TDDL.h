#pragma once
#include "plant.h"
//��������
class TDDL :
    public plant
{
public:
    TDDL();
    int status;
    int wait;
    virtual void update();
    virtual void jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball);
};

