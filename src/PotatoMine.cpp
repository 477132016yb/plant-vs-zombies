//
// Created by yb on 2024/5/12.
//

#include "PotatoMine.h"

plant::plantType PotatoMine::s_type=plantType::PotatoMine;
PotatoMine::PotatoMine() {
    this->m_dy=30;
    this->m_damage=2500;
    Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
    this->m_status=PotatoMineStatus::UnderGround;
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(true);
    this->m_action->setInterval(150);

    this->m_timer.setWaitTime(15000);
    this->m_timer.setOneTrigger(true);
    this->m_timer.setCallback([this](){
        m_status=PotatoMineStatus::Normal;
        m_isCollide=false;
    });
}

plant::plantType PotatoMine::getType() {
    return s_type;
}

void PotatoMine::skills(int delta) {
    if(m_status==PotatoMineStatus::Normal){return;}
    m_timer.update(delta);
}

void PotatoMine::draw() {
    switch (m_status) {
        case PotatoMineStatus::UnderGround:
            putimagePNG(m_x,m_y,&Singleton<res>::instanceSP()->img_PotatoMineUnderGround);
            break;
        case PotatoMineStatus::Normal:
            m_action->draw(m_x,m_y);
            break;
        case PotatoMineStatus::Boom:
            _putimagePNG(m_x,m_y,&Singleton<res>::instanceSP()->img_PotatoMineBoom);
            break;
        default:
            break;
    }
}

void PotatoMine::collide(Object *obj) {
    if(!obj->m_isCollide){return;}
    if(yb::checkHitX(obj->m_x+20,m_x-20,30)&&m_status==PotatoMineStatus::Normal){
        m_status=PotatoMineStatus::Boom;
        obj->m_blood-=m_damage;
        mciSendString("play res/music/potato_mine.mp3", 0, 0, 0);
        this->m_timer.setWaitTime(1000);
        this->m_timer.restart();
        this->m_timer.setCallback([this](){
            m_used=false;
        });
    }
}
