//
// Created by yb on 2024/4/30.
//

#include "SunFlower.h"
#include "SunShine.h"
#include "ObjManager.h"
plant::plantType SunFlower::s_type=plantType::SunFlower;

SunFlower::SunFlower() {
    Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(true);
    this->m_action->setInterval(75);
    this->m_sunSpeed=8000;
}

plant::plantType SunFlower::getType() {
    return s_type;
}

void SunFlower::skills(int delta) {
    m_skillTime+=delta;
    if(m_skillTime<m_sunSpeed){return;}
    m_skillTime = 0;
    SunShine*a = SunShine::creatSunShine(m_x,m_y);
    auto&vec = Singleton<ObjManager>::instanceSP()->getSunShineVec();
    vec.push_back(a);
}
