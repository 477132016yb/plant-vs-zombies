//
// Created by yb on 2024/5/11.
//

#include "SnowPea.h"
#include "Bullet.h"
#include "ObjManager.h"
plant::plantType SnowPea::s_type=plantType::SnowPea;
SnowPea::SnowPea() {
    Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(true);
    this->m_action->setInterval(100);
    this->m_creatSpeed=2000;
}

plant::plantType SnowPea::getType() {
    return s_type;
}

void SnowPea::skills(int delta) {
    auto &v=Singleton<ObjManager>::instanceSP()->getZombies(m_row);
    if(v.empty()){return;}
    m_skillTime+=delta;
    if(m_skillTime<m_creatSpeed){return;}
    m_skillTime = 0;
    auto*a = new Bullet(Bullet::BulletType::Cool);
    a->m_row=m_row;
    a->m_x=m_x+40,a->m_y=m_y;
    std::vector<Object*>&vec = Singleton<ObjManager>::instanceSP()->getBulletVec();
    vec.push_back(a);
}
