#pragma once
#include"vector2.h"
//—Ùπ‚¿‡
enum sunStatus{ SUNSHINE_COLLECT, SUNSHINE_DOWN, SUNSHINE_GROUND,SUNSHINE_PRODUCT
};
class sunshine
{
public:
	int img_indx;
	int timer;
	bool used;

	float t;
	vector2 p1, p2, p3, p4;
	vector2 curp;
	float speed;
	int status;
};

