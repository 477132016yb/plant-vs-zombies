//
// Created by yb on 2024/5/24.
//

#include "Car.h"

Car::Car() {
    m_speed=10;
    m_isRunning=false;
}

void Car::update(int delta) {
    StaticObj::update(delta);
    if(m_isRunning){
        m_x+=m_speed;
    }
    if(m_x>950){
        m_used=false;
    }
}

void Car::collide(Object *obj) {
    if(!obj->m_isCollide){return;}
    if(yb::checkHitX(obj->m_x,m_x+10,50)){
        if(!m_isRunning){m_isRunning=true;}
        obj->m_blood=-1;
    }
}
