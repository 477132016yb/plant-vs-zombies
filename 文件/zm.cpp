#include "zm.h"

zm::zm()
{
	this->img_numnomal = 0;
	this->img_head_indx = 0;
	this->img_numeat = 22;
	this->img_dao = 43;
	this->img_num = 59;
	this->img_dead_indx = 0;
	this->speed = 2;
	this->img_indx = rand() % 22;
	this->blood = 100;
	this->attack = 20;
	this->status = ZM_NORMAL;
	this->x = 850+ rand() % 100;
	this->row = rand() % 5;
	this->y = 30 + 100 * (this->row);
	this->type = 0;
	this->used = false;
	this->timer = 0;
	this->isbing = false;
}

void zm::update()
{
	timer++;
	col = ((x - 144) / 81) + 1;
	if (blood <= 0 && blood >= -30 && status != ZM_DAO) { status = ZM_DAO; img_indx = img_dao; }
	if (blood < -100 && status != ZM_DEAD) { status = ZM_DEAD; }
	img_indx++;
	if (status == ZM_DEAD) {
		img_dead_indx++;
		if (img_dead_indx == 20) { used = false; killcount++; }
	}
	else if (status == ZM_EAT) {
		if (img_indx == img_dao) { img_indx = img_numeat; }
	}
	else if (status == ZM_DAO) {
		img_head_indx++;
		if (img_indx >= img_num) { used = false; killcount++; img_head_indx = 0; }
	}
	else if (status == ZM_NORMAL) {
		if (img_indx >= img_numeat) { img_indx = img_numnomal; }
		if (timer >= 2) {
			x -= isbing?speed/2:speed;
			timer = 0;
		}
		if (x <= 20) {
			used = false;
		}
	}
}
