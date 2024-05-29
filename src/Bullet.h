//
// Created by yb on 2024/5/10.
//

#ifndef PVZ_BULLET_H
#define PVZ_BULLET_H
#include "Object.h"
#include "const.h"
#include "Animation.h"
#include "res.h"
#include <functional>

class Bullet : public Object{
public:
    enum class BulletType{
        Normal,Cool,Fire,Blast
    };
public:
    ~Bullet() override =default;
    explicit Bullet(Bullet::BulletType type);
public:
    void update(int delta) override;
    void draw() override;
    void collide(Object*obj) override;
    void setImage(IMAGE*img,std::vector<IMAGE>&vec);
    void setType(BulletType type);
public:
    int m_speed;
    int m_damage;
    BulletType m_type;
protected:
    BulletType m_lastType;
    IMAGE*m_img;
    std::vector<IMAGE*>m_imgs;
    int m_timer,m_idx;
};


#endif //PVZ_BULLET_H
