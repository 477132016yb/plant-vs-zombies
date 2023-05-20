#include "ttzm.h"

ttzm::ttzm()
{
	this->img_numnomal = 0;
	this->img_numeat = 15;
	this->img_num = 26;
	this->type = 2;
	this->blood = 500;
}

void ttzm::update()
{
	timer++;
	col = ((x - 144) / 81) + 1;
	if (blood <= 100 && type == 2) {
		type = 0;
		img_numnomal = 0;
		img_numeat = 22;
		img_num = 43;
	}
	if (blood <= 0) { status = ZM_DEAD; }
	img_indx++;
	if (status == ZM_DEAD) {
		img_dead_indx++;
		if (img_dead_indx == 20) { used = false; }
	}
	else if (status == ZM_EAT) {
		if (img_indx >= img_num) { img_indx = img_numeat; }
	}
	else if (status == ZM_NORMAL) {
		if (img_indx >= img_numeat) { img_indx = img_numnomal; }
		if (timer >= 2) {
			x -= speed;
			timer = 0;
		}
		if (x <= 20) {
			used = false;
		}
	}
}
