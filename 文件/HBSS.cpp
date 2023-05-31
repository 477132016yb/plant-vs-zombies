#include "HBSS.h"

HBSS::HBSS()
{
	this->cost = 175;
	this->type = 3;
	this->img_num = 8;
	this->attack = 13;
	this->card_speed = 2;
	this->count = 0;
}

void HBSS::jineng(vector<bullet>& bullets, vector<zm*>&zms, vector<sunshine>& ball)
{
	int line[5] = { 0 };
	for (auto& a : zms) {
		if (a->used && a->x < 800) {
			line[a->row] = 1;
		}
	}
	if (line[row]) {
		count++;
		if (count > 20) {
			count = 0;
			int i = 0;
			while (i < bullets.size() && bullets[i].used) { i++; }
			if (i >= bullets.size()) { return; }
			bullets[i].used = true;
			bullets[i].row = row;
			bullets[i].dx = 10;
			bullets[i].status = BULLET_BING;
			bullets[i].attack = attack;
			bullets[i].img_indx = 0;

			bullets[i].x = x + 45;
			bullets[i].y = y + 8;
		}
	}
}
