#include "SRH.h"

SRH::SRH()
{
	this->cost = 150;
	this->type = 6;
	this->img_num = 28;
	this->dy = -20;
	this->status = 0;
	this->wait = 0;
	this->card_speed = 3;
}

void SRH::update()
{
	if (status == 2 && wait++ > 500) { status = 0; wait = 0; }
	if (blood <= 0) { used = false; return; }
	if (timer++ >= endtime) {
		timer = 0;
		img_indx++;
		if (status == 0) {
			if (img_indx >= 13) { img_indx = 0; }
		}
		else if (status == 1) {
			if (img_indx >= 22) { status = 2; }
		}
		else if (status == 2) {
			if (img_indx >= img_num) { img_indx = 22; }
		}
	}
}

void SRH::jineng(vector<bullet>& bullets, vector<zm*>&zms, vector<sunshine>& ball)
{
	for (auto& a : zms) {
		if (!a->used || a->status == ZM_DEAD) { continue; }
		if (a->row == row&&a->x<x+100&&a->x>x-50&& status == 0) {
			img_indx = 13;
			status = 1;
			a->used = false;
		}
	}
}
