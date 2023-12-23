//
// Created by yb on 2024/5/2.
//

#include "Button.h"

bool Button::checkHit(int x, int y) {
    return x>=m_region.left&&x<=m_region.right&&y>=m_region.top&&y<=m_region.bottom;
}

void Button::processEvent(const ExMessage &msg) {
    switch (msg.message) {
        case WM_MOUSEMOVE:
            if(m_status==Status::Idle&& checkHit(msg.x,msg.y)){
                m_status=Status::Hovered;
            }
            else if(m_status==Status::Hovered&&!checkHit(msg.x,msg.y)){
                m_status=Status::Idle;
            }
            break;
        case WM_LBUTTONDOWN:
            if(checkHit(msg.x,msg.y)){
                m_status=Status::Pushed;
            }
            break;
        case WM_LBUTTONUP:
            if(m_status==Status::Pushed&&m_callback){
                m_callback();
            }
            break;
        default:
            break;
    }
}

void Button::draw() {
    switch (m_status) {
        case Status::Idle:
            putimagePNG(m_region.left,m_region.top,m_imgIdle);
            break;
        case Status::Hovered:
            putimagePNG(m_region.left,m_region.top,m_imgHovered);
            break;
        case Status::Pushed:
            putimagePNG(m_region.left,m_region.top,m_imgPushed);
            break;
        default:
            break;
    }
}

void Button::setRect(RECT rect) {
    m_region=rect;
}

void Button::setImage(std::vector<IMAGE> &vec) {
    m_imgIdle=&vec[0];
    m_imgHovered=&vec[1];
    m_imgPushed=&vec[2];
}

void Button::setCallback(std::function<void()> callback) {
    m_callback=callback;
}

void Button::reSet() {
    m_status=Status::Idle;
}











