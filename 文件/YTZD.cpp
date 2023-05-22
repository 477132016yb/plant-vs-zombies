#include "YTZD.h"

YTZD::YTZD()
{
	this->blood = 100;
	this->cost = 150;
	this->type = 8;
	this->img_num = 20;
	this->endtime = 1;
	this->img_boom_indx = 0;
	this->attack = 1000;
}

void YTZD::jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball)
{
	if (this->img_indx == 8) { 
		for (auto& a : zms) {
			if (!a->used|| a->status == ZM_DEAD) { continue; }
			if (a->row<=row+1&&a->row>=row-1&&a->col<=col+1&&a->col>=col-1) {
				a->blood -= attack;
			}
		}
		mciSendString("play res/music/cherrybomb.mp3", 0, 0, 0);
	}
	else if (this->img_indx == this->img_num - 1) {
		this->used = false;
	}
}
