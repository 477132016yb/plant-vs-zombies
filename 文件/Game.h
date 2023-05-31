#pragma once
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#include<thread>
#include"vector2.h"
#include"tools.h"
#include"bullet.h"
#include"sunshine.h"
#include"WDSS.h"
#include"XRK.h"
#include"HBSS.h"
#include"JGQ.h"
#include"TDDL.h"
#include"SRH.h"
#include"HJSZ.h"
#include"YTZD.h"
#include"lzzm.h"
#include"ttzm.h"
#include"glqzm.h"
#include"res.h"
#include"car.h"
#pragma comment(lib,"winmm.lib")
class Game
{
public:
	Game();
	void init();//初始化
	void updatewindow();//更新窗口
	void play();//开始游戏
	void userclick();//鼠标消息处理
	void startui();//开始界面
	void cardselectupdate();//卡牌选择时的界面刷新
	void viewshow();//展示动画及卡牌选择
	void bardown();//卡牌下拉动画
	plant* getcurplant(int i);//获取当前选择植物类型
	void updateagme();//更新游戏数据
	void updateplant();//更新植物
	void creatsunshine();//创建阳光
	void updatesunshine();//更新阳光
	void collectsun(ExMessage*msg);//收集阳光
	void creatzm();//创建僵尸
	void updatezm();//更新僵尸
	void updatecar();//更新车
	void updatebullet();//更新子弹
	void collisioncheck();//碰撞检测
	void maketype();//生成卡槽对应的植物类
private:
	res* r;//资源类
	int curx,cury;//拖动过程中的坐标
	bool chanzi;//是否选中铲子
	plant* curPlant;//选中植物
	vector<vector<plant*>>map;//植物
	vector<sunshine>ball;//阳光池
	int sun;//阳光数量
	vector<zm*>zms;//姜丝池
	vector<bullet>bullets;//子弹池
	vector<int>type;//卡槽类型
	vector<plant*>type2;//卡槽植物
	vector<car>cars;//小推车
};