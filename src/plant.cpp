//
// Created by yb on 2024/4/28.
//

#include "plant.h"

void plant::draw() {
    m_action->draw(m_x-(int)m_CameraPos.x,m_y-(int)m_CameraPos.y);
}

void plant::update(int delta) {
    if(m_blood<=0){m_used=false;}
    m_action->update(delta);
    skills(delta);
}

plant::plant() {
    m_action = std::make_shared<Animation>();
    m_skillTime = 0;
}
