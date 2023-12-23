//
// Created by yb on 2024/5/2.
//

#ifndef PVZ_CAMERA_H
#define PVZ_CAMERA_H
#include "vector2.h"
#include "Timer.h"
class Camera {
public:
    using SP=std::shared_ptr<Camera>;
    Camera();
    ~Camera()=default;
public:
    [[nodiscard]] const vector2& getPosition()const;
    void reset();
    void timerReSet();
    void update(int delta);
    void reSetSpeed(float speed);
    bool isTrigger();
public:
    void setCallback(std::function<void()> callback);
    void setWaitTime(int time);
private:
    vector2 m_pos;
    Timer::SP m_timer;
    float m_speed;
};


#endif //PVZ_CAMERA_H
