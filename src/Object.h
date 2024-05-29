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
    void SetName(const std::string& cName);//��������
    std::string getName();//��ȡ����
public:
    virtual void draw(){};//��ͼ
    virtual void update(int delta){};//����
    virtual void collide(Object*obj){};//��ײ
    virtual void setEffect(int type){};//������Ч
    virtual void collect(){};//�ռ�
public:
    int m_row,m_col;//Ŀ������������Ϣ
    int m_x{},m_y{};//����
    int m_dx=0,m_dy=0;//����ƫ����
    int m_blood=100;//Ѫ��
    bool m_used=true;//�Ƿ��ܱ������ڴ�
    bool m_isCollide=true;//�Ƿ��ܱ���ײ���
    static const vector2& m_CameraPos;//�����λ�ã���ʱδ����ʹ��
public:
    std::string className;//����
};

#endif //PVZ_OBJECT_H
