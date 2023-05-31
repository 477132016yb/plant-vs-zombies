#include "car.h"

car::car()
{
	used = true;
	speed = 15;
	x = 70;
	run = false;
}

void car::update()
{
	if (run) {
		x += speed;
	}
	if (x >= 950) {
		used = false;
	}
}
