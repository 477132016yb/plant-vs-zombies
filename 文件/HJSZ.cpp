#include "HJSZ.h"

HJSZ::HJSZ()
{
	this->blood = 100;
	this->cost = 125;
	this->type = 7;
	this->img_num = 8;
}

void HJSZ::jineng(vector<bullet>& bullets, vector<zm*>& zms, vector<sunshine>& ball)
{
	for (auto& a : bullets) {
		if (!a.used || a.status == BULLET_BLAST) { continue; }
		if (a.x > x && a.x < x + 10&&a.row==row) {
			if (a.status == BULLET_BING) {
				a.status = BULLET_NOMAL;
			}
			else if (a.status == BULLET_NOMAL) {
				a.status = BULLET_HUO;
				a.attack *= 2;
			}
		}
	}
}
