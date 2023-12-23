//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_ANIMATION_H
#define PVZ_ANIMATION_H

#include "Atlas.h"
#include "tools.h"
#include <functional>
class Animation {
public:
    using SP =std::shared_ptr<Animation>;
    Animation()=default;
    ~Animation()=default;
public:
    void reset();
    void setAtlas(Atlas::SP &atlas);
    void setLoop(bool flag);
    void setInterval(int ms);
    int getIdxFrame();
    IMAGE*getImage();
    bool checkFinished();
public:
    bool getSketch();
    void setSketch(bool flag);
    bool getCool();
    void setCool(bool flag);
public:
    void update(int delta);
    void draw(int x,int y)const;
    void setCallback(std::function<void()>callback);
private:
    bool m_isSketch=false;
    bool m_isCool=false;

    int m_timer=0;//计时器
    int m_interval=60;//帧间隔
    int m_idx=0;//帧索引
    bool m_isLoop=true;//是否循环
    Atlas::SP m_atlas= nullptr;
    std::function<void()>m_callback= nullptr;
};


#endif //PVZ_ANIMATION_H
