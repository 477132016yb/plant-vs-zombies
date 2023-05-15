#pragma once
#include<vector>
#include<easyx.h>
#include"bullet.h"
#include"zm.h"
#include"sunshine.h"
#include"tools.h"
#include<Windows.h>
#include<mmsystem.h>
using namespace std;
class plant
{
public:
	plant();
	int img_indx;
	int blood;
	int timer;
	int endtime;

	int type;
	int img_num;
	int cost;
	int attack;
	bool used;
	
	int x,y;
	int dy;
	int row,col;
	virtual void show(IMAGE*img[]);
	virtual void update();
	virtual void jineng(vector<bullet>&bullets, vector<zm*>&zms, vector<sunshine>& ball){};
};