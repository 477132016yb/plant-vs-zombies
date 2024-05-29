//
// Created by yb on 2024/4/30.
//

#include <cstdio>
#include "Atlas.h"

void Atlas::loadFromFile(LPCTSTR path, int num) {
    m_imgList.clear();
    m_imgList.resize(num);

    TCHAR path_file[64];
    for(int i=0;i<num;i++){
        sprintf_s(path_file,"%s/%d.png",path,i+1);
        loadimage(&m_imgList[i],path_file);
    }
}

void Atlas::clear() {
    m_imgList.clear();
}

int Atlas::getSize() {
    return m_imgList.size();
}

IMAGE *Atlas::getImage(int idx) {
    if(idx<0||idx>=m_imgList.size()){
        throw 0;
    }
    return &m_imgList[idx];
}

void Atlas::addImage(const IMAGE &img) {
    m_imgList.push_back(img);
}

Atlas::~Atlas() {

}

void Atlas::loadFromFile2(LPCTSTR path, int num) {
    m_imgList.clear();
    m_imgList.resize(num);

    TCHAR path_file[64];
    for(int i=0;i<num;i++){
        sprintf_s(path_file,"%s/%d.png",path,i);
        loadimage(&m_imgList[i],path_file,60,85);
    }
}
