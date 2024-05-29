//
// Created by yb on 2024/5/10.
//

#include "Bullet.h"

void Bullet::collide(Object *obj) {
    if (m_type==BulletType::Blast||!obj->m_isCollide){return;}
    if(yb::checkHitX(m_x,obj->m_x+80,30)){
        obj->m_blood-=m_damage;
        if(m_type==BulletType::Cool){
            obj->setEffect(1);
        }
        else{
            obj->setEffect(0);
        }
        setType(BulletType::Blast);
    }
}

void Bullet::draw() {
    if (m_type!=BulletType::Blast){
        putimagePNG(m_x,m_y,m_img);
    }
    else{
        putimagePNG(m_x,m_y,m_imgs[m_idx]);
    }
}

void Bullet::update(int delta) {
    m_timer+=delta;
    if(m_timer<30){return;}
    m_timer=0;
    if (m_x >= WIN_WIDTH) {
        m_used=false;
    }
    if (m_type!=BulletType::Blast) {
        m_x += m_speed;
    }
    else{
        m_idx++;
        if (m_idx == 4) {
            m_used = false;
        }
    }
}

Bullet::Bullet(BulletType type) {
    m_idx=0;
    m_timer=0;
    m_speed=10;
    m_damage=13;
    setType(type);
}

void Bullet::setImage(IMAGE *img, std::vector<IMAGE> &vec) {
    m_img=img;
    m_imgs.resize(vec.size());
    for(int i=0;i<m_imgs.size();i++){
        m_imgs[i]=&vec[i];
    }
}

void Bullet::setType(Bullet::BulletType type) {
    m_lastType=m_type;
    switch (type) {
        case BulletType::Normal:
            setImage(&Singleton<res>::instanceSP()->img_bulletNormal,Singleton<res>::instanceSP()->imgs_BlastNormal);
            break;
        case BulletType::Cool:
            setImage(&Singleton<res>::instanceSP()->img_bulletCool,Singleton<res>::instanceSP()->imgs_BlastCool);
            if(m_lastType==BulletType::Fire){
                m_damage/=2;
            }
            break;
        case BulletType::Fire:
            setImage(&Singleton<res>::instanceSP()->img_bulletFire,Singleton<res>::instanceSP()->imgs_BlastNormal);
            if(m_lastType==BulletType::Normal){
                m_damage*=2;
            }
            break;
        case BulletType::Blast:
            break;
    }
    m_type=type;
}
