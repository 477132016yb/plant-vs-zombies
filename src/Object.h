//
// Created by yb on 2024/5/2.
//

#ifndef PVZ_OBJECT_H
#define PVZ_OBJECT_H
#include <iostream>
#include <memory>
#include "Camera.h"
#include "Singleton.h"
#pragma comment(lib, "winmm.lib")
class Object{
public:
    Object()=default;
    virtual ~Object()=default;
public:
    void SetName(const std::string& cName);//设置类名
    std::string getName();//获取类名
public:
    virtual void draw(){};//绘图
    virtual void update(int delta){};//更新
    virtual void collide(Object*obj){};//碰撞
    virtual void setEffect(int type){};//设置特效
    virtual void collect(){};//收集
public:
    int m_row,m_col;//目标所在行列信息
    int m_x{},m_y{};//坐标
    int m_dx=0,m_dy=0;//坐标偏移量
    int m_blood=100;//血量
    bool m_used=true;//是否能被回收内存
    bool m_isCollide=true;//是否能被碰撞检测
    static const vector2& m_CameraPos;//摄像机位置，暂时未过多使用
public:
    std::string className;//类名
};

#endif //PVZ_OBJECT_H
