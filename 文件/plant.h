#pragma once
#include<vector>
#include<easyx.h>
#include"bullet.h"
#include"zm.h"
#include"sunshine.h"
#include"tools.h"
#include<Windows.h>
#include<mmsystem.h>
//植物基类
using namespace std;
class plant
{
public:
	plant();
	int card_time;//卡牌冷却定时
	int card_indx;//卡牌冷却图片序号
	int card_speed;//卡牌冷却速度
	int img_indx;//植物图片序号
	int blood;//血量
	int timer;//植物动作刷新定时器
	int endtime;//植物动作刷新速度

	int type;//植物类型
	int img_num;//图片总数
	int cost;//阳光花费
	int attack;//攻击力
	bool used;//是否存活
	
	int x,y;//坐标
	int dy;//垂直方向偏移量
	int row,col;//行列信息
	virtual void show(IMAGE*img[]);//贴图
	virtual void update();//数据更新
	virtual void jineng(vector<bullet>&bullets, vector<zm*>&zms, vector<sunshine>& ball){};//技能
};