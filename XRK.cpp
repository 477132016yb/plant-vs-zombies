#include "XRK.h"
XRK::XRK()
{
	this->cost = 50;
	this->type = 2;
	this->img_num = 18;

	this->time = 0;
}

void XRK::jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball)
{
	time++;
	if (time >= 200) {
		time = 0;
		int i = 0;
		while (i < ball.size() && ball[i].used) { i++; }
		if (i >= ball.size()) { return; }
		sunshine& a = ball[i];
		a.used = true;
		a.timer = 0;
		a.status = SUNSHINE_PRODUCT;
		a.p1 = vector2(x,y);
		int w = (40 + rand() % 10) * (rand() % 2 ? 1 : -1);
		a.p4 = vector2(x + w, y);
		a.p2 = vector2(a.p1.x +w* 0.3, a.p1.y - 100);
		a.p3 = vector2(a.p1.x +w* 0.7, a.p1.y - 100);
		a.t = 0;
		a.speed = 0.12;
	}
}
