//
// Created by yb on 2024/5/19.
//

#ifndef PVZ_TORCHWOOD_H
#define PVZ_TORCHWOOD_H
#include "plant.h"

class TorchWood :public plant{
public:
    TorchWood();
public:
    plantType getType() override;
    void skills(int delta)override;
private:
    static plantType s_type;
};


#endif //PVZ_TORCHWOOD_H
