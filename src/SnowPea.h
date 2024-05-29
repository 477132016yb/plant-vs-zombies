//
// Created by yb on 2024/5/11.
//

#ifndef PVZ_SNOWPEA_H
#define PVZ_SNOWPEA_H
#include "plant.h"
class SnowPea : public plant{
public:
    SnowPea();
public:
    plantType getType() override;
    void skills(int delta)override;
private:
    static plantType s_type;
    int m_creatSpeed;
};


#endif //PVZ_SNOWPEA_H
