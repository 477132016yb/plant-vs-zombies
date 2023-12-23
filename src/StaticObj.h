//
// Created by yb on 2024/5/9.
//

#ifndef PVZ_STATICOBJ_H
#define PVZ_STATICOBJ_H
#include "Object.h"
#include "tools.h"

class StaticObj :public Object{//æ≤Ã¨∂‘œÛ
public:
    StaticObj() = default;
    ~StaticObj() override = default;
    void setImage(IMAGE*img);
public:
    void draw() override;
    void update(int delta) override;
public:
    bool m_isDraw=true;
private:
    IMAGE*m_img;
};


#endif //PVZ_STATICOBJ_H
