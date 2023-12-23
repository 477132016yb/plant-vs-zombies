//
// Created by yb on 2024/5/2.
//

#ifndef PVZ_BUTTON_H
#define PVZ_BUTTON_H
#include "res.h"
#include "tools.h"
#include <vector>
#include <functional>
class Button {
public:
    using SP=std::shared_ptr<Button>;
    Button()=default;
    ~Button()=default;
public:
    void reSet();
    void setRect(RECT rect);
    void setImage(std::vector<IMAGE>&vec);
    void setCallback(std::function<void()>callback);
    void processEvent(const ExMessage&msg);
    void draw();
private:
    bool checkHit(int x,int y);
private:
    enum class Status{
    Idle,
    Hovered,
    Pushed
};
private:
    RECT m_region;
    IMAGE *m_imgIdle;
    IMAGE *m_imgHovered;
    IMAGE *m_imgPushed;
    Status m_status=Status::Idle;
    std::function<void()>m_callback;//触发回调函数
};


#endif //PVZ_BUTTON_H
