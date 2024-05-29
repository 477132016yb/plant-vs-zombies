//
// Created by yb on 2024/5/2.
//

#ifndef PVZ_TIMER_H
#define PVZ_TIMER_H
#include <functional>
#include <memory>

class Timer {
public:
    using SP=std::shared_ptr<Timer>;
    Timer()=default;
    ~Timer()=default;
public:
    void restart();
    void setWaitTime(int val);
    void setOneTrigger(bool flag);
    void setCallback(std::function<void()>callback);
    void pause();
    void resume();
    void update(int delta);
    bool isTrigger();
private:
    int m_passTime=0;//已过时间
    int m_waitTime=0;//等待时间
    bool m_isPaused=false;//是否暂停
    bool m_isTrigger=false;//是否触发
    bool m_isOneTrigger=false;//是否单次触发
    std::function<void()>m_callback;//触发回调函数
};


#endif //PVZ_TIMER_H
