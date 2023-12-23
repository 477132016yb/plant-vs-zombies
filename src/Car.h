//
// Created by yb on 2024/5/24.
//

#ifndef PVZ_CAR_H
#define PVZ_CAR_H
#include "StaticObj.h"
#include "const.h"

class Car :public StaticObj{
public:
    Car();
    ~Car() override =default;
public:
    void update(int delta) override;
    void collide(Object*obj) override;
private:
    bool m_isRunning;
    int m_speed;
};


#endif //PVZ_CAR_H
