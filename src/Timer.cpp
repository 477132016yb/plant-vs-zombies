//
// Created by yb on 2024/5/2.
//

#include "Timer.h"

void Timer::restart() {
    m_passTime=0;
    m_isTrigger=false;
}

void Timer::setWaitTime(int val) {
    m_waitTime=val;
}

void Timer::setOneTrigger(bool flag) {
    m_isOneTrigger=flag;
}

void Timer::setCallback(std::function<void()> callback) {
    m_callback=callback;
}

void Timer::pause() {
    m_isPaused=true;
}

void Timer::resume() {
    m_isPaused=false;
}

void Timer::update(int delta) {
    if(m_isPaused){
        return;
    }
    m_passTime+=delta;
    if(m_passTime>=m_waitTime){
        if((!m_isOneTrigger||!m_isTrigger)&&m_callback){
            m_callback();
        }
        m_isTrigger=true;
        m_passTime=0;
    }
}

bool Timer::isTrigger() {
    return m_isTrigger;
}
