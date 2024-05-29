//
// Created by yb on 2024/4/30.
//

#include "PeaShooter.h"
#include "Bullet.h"
#include "ObjManager.h"
plant::plantType PeaShooter::s_type=plantType::PeaShooter;
PeaShooter::PeaShooter() {
    Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(true);
    this->m_action->setInterval(75);
    this->m_creatSpeed=2000;
}

plant::plantType PeaShooter::getType() {
    return s_type;
}

void PeaShooter::skills(int delta) {
    auto &v=Singleton<ObjManager>::instanceSP()->getZombies(m_row);
    if(v.empty()){return;}
    m_skillTime+=delta;
    if(m_skillTime<m_creatSpeed){return;}
    m_skillTime = 0;
    auto*a = new Bullet(Bullet::BulletType::Normal);
    a->m_row=m_row;
    a->m_x=m_x+40,a->m_y=m_y;
    std::vector<Object*>&vec = Singleton<ObjManager>::instanceSP()->getBulletVec();
    vec.push_back(a);
}
