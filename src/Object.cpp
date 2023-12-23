//
// Created by yb on 2024/5/2.
//

#include "Object.h"
const vector2& Object::m_CameraPos=Singleton<Camera>::instance()->getPosition();
std::string Object::getName() {
    return className;
}

void Object::SetName(const std::string &cName) {
    className = cName;
}
