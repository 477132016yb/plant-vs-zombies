#pragma once
#include<time.h>
#include<iostream>
using namespace std;
//½©Ê¬»ùÀà
enum{ZM_NORMAL,ZM_DEAD,ZM_EAT,ZM_DANCE,ZM_DAO,ZM_STATUS_COUNT};
class zm
{
public:
	static int killcount;
	zm();
	int x, y;
	int img_indx;
	int img_dead_indx;
	int img_head_indx;
	int img_numnomal, img_numeat,img_dao,img_num;
	int speed;
	int row,col;
	int blood;
	int attack;
	int status;
	int type;
	int timer;
	bool used;
	bool isbing;
	virtual void update();
};

