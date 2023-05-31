#include "plant.h"

plant::plant()
{
	this->img_indx = 0;
	this->blood = 100;
	this->used = false;
	this->dy = 0;
	this->timer = 0;
	this->endtime = 0;
	this->card_speed = 1;
	this->card_time = 0;
	this->card_indx = 46;
}

void plant::show(IMAGE* img[])
{
	putimagePNG(x, y, img[img_indx]);
}

void plant::update()
{
	if (blood <= 0) { used = false; return; }
	if (timer++ >= endtime) { timer = 0; img_indx++; }
	if (img_indx >= img_num) { img_indx = 0; }
}
