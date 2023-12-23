//
// Created by yb on 2024/4/30.
//

#include "Animation.h"

#include <utility>

void Animation::reset() {
    m_timer=0;
    m_idx=0;
}

void Animation::setAtlas(Atlas::SP&atlas) {
    reset();
    m_atlas=atlas;
}

void Animation::setLoop(bool flag) {
    m_isLoop=flag;
}

void Animation::setInterval(int ms) {
    m_interval=ms;
}

bool Animation::checkFinished() {
    if(m_isLoop){
        return false;
    }
    return m_idx==m_atlas->getSize()-1;
}

IMAGE *Animation::getImage() {
    return m_atlas->getImage(m_idx);
}

int Animation::getIdxFrame() {
    return m_idx;
}

void Animation::update(int delta) {
    m_timer+=delta;
    if(m_timer>=m_interval){
        m_timer=0;
        m_idx++;
        if(m_idx>=m_atlas->getSize()){
            m_idx=m_isLoop?0:m_atlas->getSize()-1;
            if(!m_isLoop&&m_callback){
                m_callback();
            }
        }
    }
}

void Animation::draw(int x, int y) const {
    IMAGE*img=m_atlas->getImage(m_idx);
    IMAGE specialEffect;
    if(m_isCool){
        CoolImage(img,&specialEffect);
        img=&specialEffect;
    }
    else if(m_isSketch&&m_idx%2){
        SketchImage(img,&specialEffect);
        img=&specialEffect;
    }
    putimagePNG(x,y,img);
}

void Animation::setCallback(std::function<void()>callback) {
    m_callback=std::move(callback);
}

void Animation::setSketch(bool flag) {
    m_isSketch=flag;
}

bool Animation::getSketch() {
    return m_isSketch;
}

void Animation::setCool(bool flag) {
    m_isCool=flag;
}

bool Animation::getCool() {
    return m_isCool;
}

