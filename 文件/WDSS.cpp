#include "WDSS.h"

WDSS::WDSS()
{
	this->cost = 100;
	this->type = 1;
	this->img_num = 13;
	this->count = 0;
	this->attack = 13;
}

void WDSS::jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball)
{
	int line[5] = { 0 };
	for (auto& a : zms) {
		if(a->used&&a->x<800){
			line[a->row] = 1;
		}
	}
	if (line[row]) {
		count++;
		if (count > 20) {
			count = 0;
			int i = 0;
			while (i < bullets.size()&&bullets[i].used) {i++;}
			if (i >= bullets.size()) { return; }
			bullet& a = bullets[i];
			a.used = true;
			a.row = row;
			a.dx = 10;
			a.attack = attack;
			a.status = BULLET_NOMAL;
			a.img_indx = 0;

			a.x = x + 45;
			a.y = y + 8;
		}
	}
}
