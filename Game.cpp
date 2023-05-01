#include "Game.h"
#define WIN_WIDTH 900
#define WIN_HIGHT 600

Game::Game() {
	img_bg = new IMAGE;
	img_bar = new IMAGE;
	img_bullet_normal = new IMAGE;
	img_bullet_bing = new IMAGE;
	img_bullet_huo = new IMAGE;
	for (int i = 0; i < 4; i++) {
		img_bullet_blast[i] = new IMAGE;
	}
	for (int i = 0; i < ZW_COUNT; i++) {
		img_card[i] = new IMAGE;
		for (int j = 0; j < 30; j++) {
			img_zhiwu[i][j] = new IMAGE;
		}
	}
	for (int i = 0; i < 29; i++) {
		img_sunshine[i] = new IMAGE;
	}
	for (int i = 0; i < ZM_COUNT; i++) {
		for (int j = 0; j < 50; j++) {
			img_zm[i][j] = new IMAGE;
		}
	}
	for (int i = 0; i < 20; i++) {
		img_zm_dead[i] = new IMAGE;
	}

	for (int i = 0; i < 11; i++) {
		img_zm_stand[i] = new IMAGE;
	}
	curPlant = NULL;
	map = vector<vector<plant*>>(5, vector<plant*>(10,NULL));
	zms = vector<zm*>(20, new zm);
	ball.resize(10);
	bullets.resize(20);
	sun = 150;
}

void Game::init()
{
	srand(time(NULL));
	loadimage(img_bg, "res/bg.jpg");
	loadimage(img_bar, "res/bar5.png");
	loadimage(img_bullet_normal, "res/bullets/bullet_normal.png");
	loadimage(img_bullet_bing, "res/bullets/bullet_bing.png");
	loadimage(img_bullet_huo, "res/bullets/bullet_huo.png");
	for (int i = 0; i < 4;i++) {
		float k = (i + 1) * 0.2;
		loadimage(img_bullet_blast[i], "res/bullets/bullet_blast.png",
			img_bullet_blast[i]->getwidth()*k, img_bullet_blast[i]->getheight() * k,true);
	}
	char name[64];
	for (int i = 0; i < ZW_COUNT; i++) {
		sprintf_s(name, sizeof(name), "res/Cards/card_%d.png", i + 1);
		loadimage(img_card[i], name);
		int j = 0;
		while(1) {
			sprintf_s(name, sizeof(name), "res/zhiwu/%d/%d.png", i, j+1);
			if (checkfile(name)) {
				loadimage(img_zhiwu[i][j], name);
				j++;
			}
			else { break; }
		}
	}
	for (int i = 0; i < 29; i++) {
		sprintf_s(name, sizeof(name), "res/sunshine/%d.png", i + 1);
		loadimage(img_sunshine[i], name);
	}
	for (int i = 0; i < ZM_COUNT; i++) {
		int j = 0;
		while (1) {
			sprintf_s(name, sizeof(name), "res/zm/%d/%d.png", i, j + 1);
			if (checkfile(name)) {
				loadimage(img_zm[i][j], name);
				j++;
			}
			else { break; }
		}
	}
	for (int i = 0; i < 20; i++) {
		sprintf_s(name, sizeof(name), "res/zm_dead/%d.png", i + 1);
		loadimage(img_zm_dead[i], name);
	}
	for (int i = 0; i < 11; i++) {
		sprintf_s(name, sizeof(name), "res/zm_stand/%d.png", i + 1);
		loadimage(img_zm_stand[i], name);
	}
	initgraph(WIN_WIDTH,WIN_HIGHT);
	//��������
	LOGFONT f;
	gettextstyle(&f);
	strcpy(f.lfFaceName, "Segoe UI Black");
	f.lfQuality = ANTIALIASED_QUALITY;//�����
	f.lfHeight = 25;
	f.lfWidth = 10;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	mciSendString("play res/bg.mp3", 0, 0, 0);
}

void Game::updatewindow()
{
	BeginBatchDraw();
	putimage(-112, 0, img_bg);
	char name[64];
	for (auto&a:map) {
		for (auto&b:a) {
			if (b&&b->used) {
				b->show(img_zhiwu[b->type - 1]);
			}
		}
	}
	if (curPlant) {
		IMAGE* img = img_zhiwu[curPlant->type - 1][0];
		putimagePNG(curx - img->getwidth() / 2, cury - img->getheight() / 2, img);
	}
	for (auto& a : zms) {
		if (a->used) {
			IMAGE* img1 = img_zm[a->type][a->img_indx];
			IMAGE* img2 = img_zm_dead[a->img_dead_indx];
			if (a->status==ZM_DEAD) {
				putimagePNG(a->x, a->y, img2);
			}
			else {
				putimagePNG(a->x, a->y, img1);
			}
		}
	}
	for (auto& a : bullets) {
		if (a.used) {
			IMAGE* img1 = img_bullet_normal;
			IMAGE* img2 = img_bullet_blast[a.img_indx];
			IMAGE* img3 = img_bullet_bing;
			IMAGE* img4 = img_bullet_huo;
			if (a.status == BULLET_NOMAL) {
				putimagePNG(a.x, a.y, img1);
			}
			else if (a.status == BULLET_BING) {
				putimagePNG(a.x, a.y, img3);
			}
			else if (a.status == BULLET_BLAST) {
				putimagePNG(a.x, a.y, img2);
			}
			else if (a.status == BULLET_HUO) {
				putimagePNG(a.x, a.y, img4);
			}
		}
	}
	putimagePNG(250 - 112, 0, img_bar);
	for (int i = 0; i < ZW_COUNT; i++) {
		putimagePNG(339 - 112 + i * 64, 8, img_card[i]);
	}
	for (auto& a : ball) {
		if (a.used) {
			IMAGE* img = img_sunshine[a.img_indx];
			putimagePNG(a.curp.x, a.curp.y, img);
		}
	}
	char score[8];
	sprintf_s(score, sizeof(score), "%d", sun);
	outtextxy(278-112, 69, score);
	EndBatchDraw();
}

void Game::play()
{
	init();
	startui();
	viewshow();
	bardown();
	int timer = 0;
	bool flag = false;
	while (1) {
		userclick();
		timer += getDelay();
		if (timer > 75) {
			timer = 0;
			flag = true;
		}
		if (flag) {
			flag = false;
			updatewindow();
			updateagme();
		}
	}
}

void Game::updatesunshine() {
	for (auto& a : ball) {
		if (a.used) {
			a.img_indx = (a.img_indx + 1) % 29;
			if (a.status == SUNSHINE_DOWN) {
				a.t += a.speed;
				a.curp = a.p1 + a.t * (a.p4 - a.p1);
				if (a.t >= 1) {
					a.status = SUNSHINE_GROUND;
					a.timer = 0;
					a.t = 0;
				}
			}
			else if (a.status == SUNSHINE_GROUND) {
				a.timer++;
				if (a.timer >= 100) {
					a.used = false;
				}
			}
			else if (a.status == SUNSHINE_COLLECT) {
				a.t += a.speed;
				a.curp = a.p1 + a.t * (a.p4 - a.p1);
				if (a.t >= 1) {
					a.used = false;
					sun += 25;
				}
			}
			else if (a.status == SUNSHINE_PRODUCT) {
				a.t += a.speed;
				a.curp = calcBezierPoint(a.t, a.p1, a.p2, a.p3, a.p4);
				if (a.t >= 1) {
					a.status = SUNSHINE_GROUND;
					a.timer = 0;
					a.t = 0;
				}
			}
		}
	}
}

void Game::viewshow()
{
	int minx = WIN_WIDTH - img_bg->getwidth();
	vector2 points[9] = {
		{550,80},{530,160},{630,170},{530,200},{515,270},
		{565,370},{605,340},{705,280},{690,340}
	};
	int indxs[9];
	for (auto& a : indxs) {
		a = rand() % 11;
	}
	int count = 0;
	for(int x=0;x>=minx;x-=2){
		BeginBatchDraw();
		putimage(x, 0, img_bg);
		count++;
		for (int i = 0; i < 9;i++) {
			putimagePNG(points[i].x - minx + x, points[i].y, img_zm_stand[indxs[i]]);
			if (count > 3) {
				indxs[i] = (indxs[i] + 1) % 11;
			}
		}
		if (count > 3) { count = 0; }
		EndBatchDraw();
		Sleep(5);
	}
	for (int i = 0; i < 100; i++) {
		BeginBatchDraw();
		putimage(minx, 0, img_bg);
		count++;
		for (int i = 0; i < 9; i++) {
			putimagePNG(points[i].x, points[i].y, img_zm_stand[indxs[i]]);
			if (count > 3) {
				indxs[i] = (indxs[i] + 1) % 11;
			}
		}
		if (count > 3) { count = 0; }
		EndBatchDraw();
		Sleep(10);
	}
	for (int x = minx; x <= -112; x += 2) {
		BeginBatchDraw();
		putimage(x, 0, img_bg);
		count++;
		for (int i = 0; i < 9; i++) {
			putimagePNG(points[i].x + x-minx, points[i].y, img_zm_stand[indxs[i]]);
			if (count > 3) {
				indxs[i] = (indxs[i] + 1) % 11;
			}
		}
		if (count > 3) { count = 0; }
		EndBatchDraw();
		Sleep(5);
	}
}

void Game::bardown()
{
	int height = img_bar->getheight();
	for (int y = -height; y <= 0; y++) {
		BeginBatchDraw();
		putimage(-112, 0, img_bg);
		putimagePNG(250 - 112, y, img_bar);
		for (int i = 0; i < ZW_COUNT; i++) {
			putimagePNG(339 - 112 + i * 64, y+8, img_card[i]);
		}
		EndBatchDraw();
		Sleep(5);
	}
}

void Game::creatsunshine() {
	static int count = 0;
	count++;
	static int fre = 10;
	if (count > fre) {
		count = 0;
		fre = 200 + rand() % 100;
		int i = 0;
		while (i<ball.size()&&ball[i].used) { i++; }
		if (i >= ball.size()) { return; }
		sunshine& a = ball[i];
		a.used = true;
		a.timer = 0;
		a.status = SUNSHINE_DOWN;
		a.p1 = vector2(260 + rand() % 640, 60);
		a.p4 = vector2(a.p1.x, 230 + (rand() % 4) * 90);
		a.t=0;
		float distance = dis(a.p1 - a.p4);
		float off = 5;
		a.speed = 1.0 / (distance / off);
	}
}

void Game::updateagme() {
	collisioncheck();
	updateplant();
	creatsunshine();
	updatesunshine();
	creatzm();
	updatezm();
	updatebullet();
}

void Game::updateplant()
{
	for (auto& a : map) {
		for (auto& b : a) {
			if (b&&b->used) {
				b->update();
				b->jineng(bullets, zms, ball);
			}
		}
	}
}

void Game::startui()
{
	IMAGE menu, menu1, menu2;
	loadimage(&menu, "res/menu.png");
	loadimage(&menu1, "res/menu1.png");
	loadimage(&menu2, "res/menu2.png");
	bool flag = false;
	while (1) {
		BeginBatchDraw();
		putimage(0, 0, &menu);
		putimagePNG(474, 75, flag ? &menu1 : &menu2);
		ExMessage msg;
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN &&
				msg.x > 474 && msg.x < 474 + 300 &&
				msg.y>75 && msg.y < 75 + 140) {
				flag = true;
			}
			if (msg.message == WM_LBUTTONUP && flag) {
				mciSendString("stop res/bg.mp3", 0, 0, 0);
				mciSendString("play res/UraniwaNi.mp3 repeat", 0, 0, 0);
				EndBatchDraw();
				break;
			}
		}
		EndBatchDraw();
	}
}


void Game::collectsun(ExMessage* msg){
	int w = img_sunshine[0]->getwidth();
	int h = img_sunshine[0]->getheight();
	for (auto& a : ball) {
		if (a.used) {
			int x = a.curp.x;
			int y = a.curp.y;
			if (msg->x > x && msg->x<x + w && msg->y>y && msg->y < y + h) {
				PlaySound(TEXT("res/sunshine.wav"), NULL, SND_FILENAME | SND_ASYNC);
				a.status = SUNSHINE_COLLECT;
				a.t = 0;
				a.p1.x = a.curp.x;
				a.p1.y = a.curp.y;
				a.p4 = vector2(150, 0);
				float distance = dis(a.p1 - a.p4);
				float off = 50;
				a.speed = 1.0/(distance/off);
				break;
			}
		}
	}
}

void Game::creatzm()
{
	static int count = 0;
	count++;
	static int fre = 10;
	if (count > fre) {
		count = 0;
		fre = 100 + rand() % 150;
		int i = 0;
		while (zms[i]->used&&i < zms.size()) { i++; }
		if (i >= zms.size()) { return; }
		int ran = rand() % 6;
		switch (ran)
		{
		case 0:
			zms[i] = new zm;
			break;
		case 1:
			zms[i] = new lzzm;
			break;
		case 2:
			zms[i] = new ttzm;
			break;
		case 3:
			zms[i] = new glqzm;
			break;
		default:
			zms[i] = new zm;
			break;
		}
		zms[i]->used = true;
	}
}

void Game::updatezm()
{
	for (auto& a : zms) {
		if (a->used) {
			a->update();
		}
	}
}

void Game::updatebullet()
{
	for (auto& a : bullets) {
		if (a.used) {
			a.x += a.dx;
			if (a.x >= WIN_WIDTH) {
				a.used=false;
			}
			if (a.status==BULLET_BLAST) {
				a.img_indx++;
				if (a.img_indx == 4) {
					a.used = false;
					a.status = BULLET_NOMAL;
				}
			}
		}
	}
}

void Game::collisioncheck()
{
	for (auto& b : zms) {
		if (!b->used|| b->status==ZM_DEAD) { continue; }
		for (auto& a : bullets) {
			if (!a.used || a.status==BULLET_BLAST) { continue; }
			int x1 = b->x + 80;
			int x2 = b->x + 110;
			int x = a.x;
			if (a.row == b->row && x > x1 && x < x2) {
				if (a.status == BULLET_BING&&(b->speed==2|| b->speed == 4)) {
					mciSendString("play res/frozen.mp3", 0, 0, 0);
					b->speed /= 2;
				}
				if(b->type==2){ PlaySound(TEXT("res/shieldhit.wav"), NULL, SND_FILENAME | SND_ASYNC); }
				else{ PlaySound(TEXT("res/splat2.wav"), NULL, SND_FILENAME | SND_ASYNC); }
				b->blood -= a.attack;
				a.dx = 0;
				a.status = BULLET_BLAST;
			}
		}
		for (auto& c : map) {
			for (auto& d : c) {
				if (!d) { continue; }
				int x = b->x + 80;
				int x1 = d->x + 10;
				int x2 = d->x + 60;
				if (d->row == b->row && x > x1 && x < x2 ) {
					if (d->used) {
						static int count = 9;
						count++;
						if (count > 10) {
							if (b->status == ZM_NORMAL) { b->status = ZM_EAT; b->img_indx = b->img_numeat; }
							mciSendString("play res/chompsoft.mp3", 0, 0, 0);
							if (count > 20) {
								count = 0;
								d->blood -= b->attack;
								mciSendString("play res/chomp.mp3", 0, 0, 0);
							}
						}
					}
					else {
						b->status = ZM_NORMAL;
					}
				}
			}
		}
	}
}

void Game::userclick()
{
	ExMessage msg;
	static int status = 0;
	if (peekmessage(&msg)) {
		if (msg.message == WM_LBUTTONDOWN) {//��갴��
			if (msg.x > 227 && msg.x < 227 + 64 * ZW_COUNT && msg.y < 96 && msg.y>8) {
				curPlant= getcurplant((msg.x - (227)) / 64);
				status = 1;
			}
			else {
				collectsun(&msg);
			}
		}
		else if (msg.message == WM_MOUSEMOVE&&status==1) {//����϶�
			curx = msg.x, cury = msg.y;
		}
		else if (msg.message == WM_LBUTTONUP) {
			int x = msg.x;
			int y = msg.y;
			if (x > 144 && y > 77 && y < 591) {
				int row = (y - 77) / 102;
				int col = (x - 144) / 81;
				if (curPlant&&(!map[row][col] ||!map[row][col]->used) && status == 1 && sun >= curPlant->cost) {
					curPlant->y = 77 + row * 102+curPlant->dy;
					curPlant->x = 144 + col * 81;
					curPlant->row = row;
					curPlant->col = col;
					curPlant->used = true;
					map[row][col] = curPlant;
					sun -= map[row][col]->cost;
					PlaySound(TEXT("res/plant1.wav"), NULL, SND_FILENAME | SND_ASYNC);
					status = 0;
				}
			}
			curPlant = NULL;
		}
	}
}


plant* Game::getcurplant(int i)
{
	switch (i)
	{
	case 0:
		return new WDSS;
		break;
	case 1:
		return new XRK;
		break;
	case 2:
		return new HBSS;
		break;
	case 3:
		return new JGQ;
		break;
	case 4:
		return new TDDL;
		break;
	case 5:
		return new SRH;
		break;
	case 6:
		return new HJSZ;
		break;
	case 7:
		return new YTZD;
		break;
	default:
		break;
	}
	return nullptr;
}

bool Game::checkfile(const char* name)
{
	FILE* fp = fopen(name, "r");
	if (fp) { fclose(fp); }
	return fp!=NULL;
}