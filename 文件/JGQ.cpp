#include "JGQ.h"

JGQ::JGQ()
{
	this->blood = 300;
	this->status = 0;
	this->cost = 50;
	this->type = 4;
	this->img_num = 30;
	this->endtime = 1;
	this->card_speed = 5;
}

void JGQ::update()
{
	if (blood < 200 && blood >= 100 && status == 0) { status = 1; img_indx = 8; }
	else if (blood < 100 && blood > 0 && status == 1) { status = 2; img_indx = 19;}
	else if(blood <= 0) { used = false; return; }

	if (timer++ >= endtime) {
		timer = 0;
		img_indx++;
		if (status == 0) {
			if (img_indx >= 8) { img_indx = 0; }
		}
		else if (status == 1) {
			if (img_indx >= 19) { img_indx = 8; }
		}
		else if (status == 2) {
			if (img_indx >= img_num) { img_indx = 19; }
		}
	}
}
