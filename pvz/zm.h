#pragma once
#include<time.h>
#include<iostream>
using namespace std;
enum{ZM_NORMAL,ZM_DEAD,ZM_EAT,ZM_DANCE,ZM_STATUS_COUNT};
class zm
{
public:
	zm();
	int x, y;
	int img_indx;
	int img_dead_indx;
	int img_numnomal, img_numeat,img_num;
	int speed;
	int row,col;
	int blood;
	int attack;
	int status;
	int type;
	int timer;
	bool used;
	virtual void update();
};

