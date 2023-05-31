#include "TDDL.h"

TDDL::TDDL()
{
	this->cost = 25;
	this->type = 5;
	this->img_num = 10;
	this->dy = 20;
	this->endtime = 3;
	this->attack = 1000;
	this->status = 0;
	this->wait = 0;
	this->card_speed = 5;
}

void TDDL::update()
{
	if (status == 0 && wait++ > 200) { status = 1; wait = 0; }
	if (blood <= 0) { used = false; return; }
	if (timer++ >= endtime) { 
		timer = 0;
		if (status == 1) {
			img_indx++;
			if (img_indx >= 8) { img_indx = 1; }
		}
		else if (status == 2) {
			img_indx++;
			if(img_indx>=img_num){ this->used = false; }
		}
	}
}

void TDDL::jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball)
{
	for (auto& a : zms) {
		if (!a->used|| a->status == ZM_DEAD) { continue; }
		if (a->x<x - 10 && a->x>x - 70 &&a->row==row&&status==1) {
			mciSendString("play res/music/potato_mine.mp3", 0, 0, 0);
			a->blood -= attack;
			this->status = 2;
			img_indx = 8;
		}
	}
}
