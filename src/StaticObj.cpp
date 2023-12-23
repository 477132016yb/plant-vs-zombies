//
// Created by yb on 2024/5/9.
//

#include "StaticObj.h"

void StaticObj::draw() {
    if(m_isDraw){
        putimagePNG(m_x,m_y,m_img);
    }
}

void StaticObj::update(int delta) {
    Object::update(delta);
}

void StaticObj::setImage(IMAGE *img) {
    m_img = img ;
}
