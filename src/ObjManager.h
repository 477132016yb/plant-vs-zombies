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
class ObjManager {//对象管理者
public:
    using SP=std::shared_ptr<ObjManager>;
    ObjManager();
    ~ObjManager();
    std::vector<Object*>& getSunShineVec();//获取阳光池
    std::vector<Object*>& getBulletVec();//获取子弹池
    std::vector<Object*>& getZombies(int row);//获取某行僵尸池
public:
    void update(int delta);
    void draw();
    void input(const ExMessage& msg);
    void init();//初始化
private:
    void processLeftButton(const ExMessage& msg);//处理左键按下
    void checkSunShine(const ExMessage& msg);//收集阳光
    void updateMemory();//内存回收
private:
    void creatObject(int delta);//创建对象
    void creatSunShine(int delta);//创建阳光
    void creatZombie(int delta);//创建僵尸
private:
    void processCollide();//碰撞处理
    void collideVec(std::vector<Object*>&v1,std::vector<Object*>&v2);
private:
    int m_sun;//阳光
    Object*m_cur;//当前临时对象指针，铲子或者植物
    StaticObj *m_shovelObj;//铲子指针
    StaticObj *m_virtualPlant;//虚化图片指针
    std::vector<std::vector<Object*>>m_plantMap;//植物图
    std::vector<std::vector<Object*>>m_zombiePool;//僵尸池
    std::vector<Object*>m_sunShinePool;//阳光池
    std::vector<Object*>m_bulletPool;//子弹池
    std::vector<Animation::SP>m_cardCoolAtion;//卡牌冷却动画数组
    std::vector<StaticObj*>m_car;//小推车
    bool m_isMove;//鼠标是否在虚化图片选中时移动
};


#endif //PVZ_OBJMANAGER_H
