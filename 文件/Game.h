#pragma once
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
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
#include "res.h"
#pragma comment(lib,"winmm.lib")
class Game
{
public:
	Game();
	void init();
	void updatewindow();
	void play();
	void userclick();
	void startui();
	void cardselect();
	void viewshow();
	void bardown();
	plant* getcurplant(int i);
	void updateagme();
	void updateplant();
	void creatsunshine();
	void updatesunshine();
	void collectsun(ExMessage*msg);
	void creatzm();
	void updatezm();
	void updatebullet();
	void collisioncheck();
private:
	res* r;//资源类
	int curx,cury;//拖动过程中的坐标
	plant* curPlant;//选中植物
	vector<vector<plant*>>map;//植物
	vector<sunshine>ball;//阳光池
	int sun;//阳光数量
	vector<zm*>zms;//姜丝池
	vector<bullet>bullets;//子弹池
	vector<int>type;//卡槽类型
};