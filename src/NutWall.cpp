//
// Created by yb on 2024/5/11.
//

#include "NutWall.h"
plant::plantType NutWall::s_type=plantType::NutWall;
NutWall::NutWall() {
    this->setStatus(NutWallStatus::Normal);
    this->m_action->setLoop(true);
    this->m_action->setInterval(75);
    this->m_blood=300;
}

plant::plantType NutWall::getType() {
    return s_type;
}

void NutWall::setStatus(NutWall::NutWallStatus status) {
    m_status = status;
    Atlas ::SP atlas;
    switch (status) {
        case NutWallStatus::Normal:
            atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
            break;
        case NutWallStatus::Injured:
            atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atl_NutInjured);
            break;
        case NutWallStatus::NearDeath:
            atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atl_NutNearDeath);
            break;
    }
    this->m_action->setAtlas(atlas);
}

void NutWall::skills(int delta) {
    m_skillTime+=delta;
    if(m_skillTime<60){return;}
    m_skillTime = 0;
    if(m_blood<200&&m_status==NutWallStatus::Normal){
        setStatus(NutWallStatus::Injured);
    }
    if(m_blood<100&&m_status==NutWallStatus::Injured){
        setStatus(NutWallStatus::NearDeath);
    }
}
