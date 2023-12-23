//
// Created by yb on 2024/5/11.
//

#ifndef PVZ_NUTWALL_H
#define PVZ_NUTWALL_H

#include "plant.h"
class NutWall :public plant{
public:
    NutWall();
public:
    enum class NutWallStatus{
        Normal,
        Injured,
        NearDeath
    };
public:
    plantType getType() override;
    void skills(int delta)override;
private:
    void setStatus(NutWallStatus status);
private:
    static plantType s_type;
    NutWallStatus m_status;
};


#endif //PVZ_NUTWALL_H
