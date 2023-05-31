#include "lzzm.h"

lzzm::lzzm()
{
	this->img_numnomal = 0;
	this->img_numeat = 21;
	this->img_num = 32;
	this->type = 1;
	this->blood = 300;
}

void lzzm::update()
{
	timer++;
	col = ((x - 144) / 81) + 1;
	if (blood <= 100&& type==1) {
		type = 0;
		img_numnomal = 0;
		img_numeat = 22;
		img_dao = 43;
		img_num = 59;
	}
	if (blood <= 0 && blood >= -30 && status != ZM_DAO) { status = ZM_DAO; img_indx = img_dao; }
	if (blood < -100 && status != ZM_DEAD) { status = ZM_DEAD; }
	img_indx++;
	if (status == ZM_DEAD) {
		img_dead_indx++;
		if (img_dead_indx == 20) { used = false; killcount++;}
	}
	else if (status == ZM_EAT) {
		if (img_indx >= img_num) { img_indx = img_numeat; }
	}
	else if (status == ZM_DAO) {
		img_head_indx++;
		if (img_indx >= img_num) { used = false; killcount++; img_head_indx = 0; }
	}
	else if (status == ZM_NORMAL) {
		if (img_indx >= img_numeat) { img_indx = img_numnomal; }
		if (timer >= 2) {
			x -= isbing ? speed / 2 : speed;
			timer = 0;
		}
		if (x <= 20) {
			used = false;
		}
	}
}
