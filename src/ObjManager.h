//
// Created by yb on 2024/5/7.
//

#ifndef PVZ_OBJMANAGER_H
#define PVZ_OBJMANAGER_H

#include "Object.h"
#include <ctime>
#include "SceneManager.h"
#include "Animation.h"
#include "StaticObj.h"
class ObjManager {//���������
public:
    using SP=std::shared_ptr<ObjManager>;
    ObjManager();
    ~ObjManager();
    std::vector<Object*>& getSunShineVec();//��ȡ�����
    std::vector<Object*>& getBulletVec();//��ȡ�ӵ���
    std::vector<Object*>& getZombies(int row);//��ȡĳ�н�ʬ��
public:
    void update(int delta);
    void draw();
    void input(const ExMessage& msg);
    void init();//��ʼ��
private:
    void processLeftButton(const ExMessage& msg);//�����������
    void checkSunShine(const ExMessage& msg);//�ռ�����
    void updateMemory();//�ڴ����
private:
    void creatObject(int delta);//��������
    void creatSunShine(int delta);//��������
    void creatZombie(int delta);//������ʬ
private:
    void processCollide();//��ײ����
    void collideVec(std::vector<Object*>&v1,std::vector<Object*>&v2);
private:
    int m_sun;//����
    Object*m_cur;//��ǰ��ʱ����ָ�룬���ӻ���ֲ��
    StaticObj *m_shovelObj;//����ָ��
    StaticObj *m_virtualPlant;//�黯ͼƬָ��
    std::vector<std::vector<Object*>>m_plantMap;//ֲ��ͼ
    std::vector<std::vector<Object*>>m_zombiePool;//��ʬ��
    std::vector<Object*>m_sunShinePool;//�����
    std::vector<Object*>m_bulletPool;//�ӵ���
    std::vector<Animation::SP>m_cardCoolAtion;//������ȴ��������
    std::vector<StaticObj*>m_car;//С�Ƴ�
    bool m_isMove;//����Ƿ����黯ͼƬѡ��ʱ�ƶ�
};


#endif //PVZ_OBJMANAGER_H
