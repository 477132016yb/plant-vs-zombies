//
// Created by yb on 2024/5/5.
//

#include "SunShine.h"
void SunShine::update(int delta) {
    m_action->update(delta);
    switch (m_status) {
        case SunStatus::SUNSHINE_DOWN:
            m_t += m_speed;
            m_curp = p1 + m_t * (p4 - p1);
            if (m_t >= 1) {
                m_status = SunStatus::SUNSHINE_GROUND;
                m_timer = 0;
                m_t = 0;
            }
            break;
        case SunStatus::SUNSHINE_GROUND:
            m_timer+=delta;
            if (m_timer >= 4000) {
                m_used=false;
                m_timer=0;
            }
            break;
        case SunStatus::SUNSHINE_COLLECT:
            m_t += m_speed;
            m_curp = p1 + m_t * (p4 - p1);
            if (m_t >= 1) {
                m_used=false;
            }
            break;
        case SunStatus::SUNSHINE_PRODUCT:
            m_t += m_speed;
            m_curp = vector2::calcBezierPoint(m_t, p1, p2, p3, p4);
            if (m_t >= 1) {
                m_status = SunStatus::SUNSHINE_GROUND;
                m_timer = 0;
                m_t = 0;
            }
            break;
        default:
            break;
    }
}

void SunShine::draw() {
    m_x=(int)m_curp.x;
    m_y=(int)m_curp.y;
    if(m_used){
        m_action->draw(m_x-(int)m_CameraPos.x,m_y-(int)m_CameraPos.y);
    }
}

SunShine::SunShine() {
    m_action = std::make_shared<Animation>();
    Atlas::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atl_sunShine);
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(true);
    this->m_action->setInterval(75);

    m_status = SunShine::SunStatus::SUNSHINE_DOWN;
    p1 = vector2(260 + rand() % 540, 60);
    p4 = vector2(p1.x, 230 + (rand() % 4) * 90);
    m_t=0;
    float distance = (p1 - p4).dis();
    float off = 1;
    m_speed = 1.0 / (distance / off);
}


SunShine *SunShine::creatSunShine(int x, int y) {
    SunShine*a=new SunShine();
    a->m_status = SunShine::SunStatus::SUNSHINE_PRODUCT;
    a->p1 = vector2(x,y);
    int w = (40 + rand() % 10) * (rand() % 2 ? 1 : -1);
    a->p4 = vector2(x + w, y);
    a->p2 = vector2(a->p1.x +w* 0.3, a->p1.y - 100);
    a->p3 = vector2(a->p1.x +w* 0.7, a->p1.y - 100);
    a->m_t = 0;
    a->m_speed = 0.06;
    return a;
}

void SunShine::collect() {
    m_status = SunShine::SunStatus::SUNSHINE_COLLECT;
    m_t = 0;
    p1.x = m_curp.x;
    p1.y = m_curp.y;
    p4 = vector2(150, 0);
    float distance = (p1 - p4).dis();
    float off = 50;
    m_speed = 1.0/(distance/off);
}
