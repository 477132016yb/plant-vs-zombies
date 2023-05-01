#pragma once
enum{BULLET_NOMAL,BULLET_BING, BULLET_HUO, BULLET_BLAST};
class bullet
{
public:
	int x, y;
	int dx;
	int row;
	int attack;
	bool used;
	int status;
	int img_indx;
};