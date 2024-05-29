//
// Created by yb on 2024/5/19.
//

#include "TorchWood.h"
#include "Bullet.h"
#include "ObjManager.h"
plant::plantType TorchWood::s_type=plantType::TorchWood;
TorchWood::TorchWood() {
    Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(true);
    this->m_action->setInterval(75);
}

plant::plantType TorchWood::getType() {
    return s_type;
}

void TorchWood::skills(int delta) {
    std::vector<Object*>&vec = Singleton<ObjManager>::instanceSP()->getBulletVec();
    if(vec.empty()){return;}
    m_skillTime+=delta;
    if(m_skillTime<20){return;}
    m_skillTime = 0;
    for(auto & a :vec){
        if(!a){continue;}
        auto b=dynamic_cast<Bullet*>(a);
        if(b->m_type==Bullet::BulletType::Blast){ continue;}
        if(b->m_row==m_row&&yb::checkHitX(b->m_x,m_x,10)){
            if(b->m_type==Bullet::BulletType::Normal){
                b->setType(Bullet::BulletType::Fire);
            }
            else if(b->m_type==Bullet::BulletType::Cool){
                b->setType(Bullet::BulletType::Normal);
            }
        }
    }
}
