//
// Created by yb on 2024/5/2.
//

#include "Camera.h"

#include <utility>

const vector2 &Camera::getPosition() const {
    return m_pos;
}

void Camera::update(int delta) {
    m_pos.x += m_speed* (float)delta;
    m_timer->update(delta);
}

void Camera::reset() {
    m_pos.x=0;
    m_pos.y=0;
}

Camera::Camera() {
    m_speed=0.2;
    m_timer=std::make_shared<Timer>();
    m_timer->setWaitTime(2500);
    m_timer->setOneTrigger(true);
    m_timer->setCallback([this](){
        m_speed=0;
    });
}

void Camera::timerReSet() {
    m_timer->restart();
}

void Camera::reSetSpeed(float speed) {
    m_speed=speed;
}

bool Camera::isTrigger() {
    return m_timer->isTrigger();
}

void Camera::setCallback(std::function<void()> callback) {
    m_timer->setCallback(std::move(callback));
}

void Camera::setWaitTime(int time) {
    m_timer->setWaitTime(time);
}
