#include "Game.h"
#define WIN_WIDTH 900
#define WIN_HIGHT 600
res* res::m_res = NULL;
int zm::killcount = 0;
Game::Game() {
	r = res::getres();
	curPlant = NULL;
	map = vector<vector<plant*>>(5, vector<plant*>(10,NULL));
	type2 = vector<plant*>(8, NULL);
	zms = vector<zm*>(20, new zm);
	type = vector<int>(8,-1);
	//type = vector<int>{7,6,5,4,3,2,1,0};
	cars.resize(5);
	ball.resize(10);
	bullets.resize(20);
	sun = 150;
	chanzi = false;
}

void Game::init()
{
	srand(time(NULL));
	r->init();
	for (int i = 0; i < 5; i++) {
		cars[i].y = 120 + i * 97;
		cars[i].row = i;
	}
	initgraph(WIN_WIDTH,WIN_HIGHT);
	//设置字体
	LOGFONT f;
	gettextstyle(&f);
	strcpy(f.lfFaceName, "Segoe UI Black");
	f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿
	f.lfHeight = 25;
	f.lfWidth = 10;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	mciSendString("play res/music/bg.mp3", 0, 0, 0);
}

void Game::updatewindow()
{
	BeginBatchDraw();
	putimage(-112, 0, r->img_bg);
	char name[64];
	putimagePNG(250 - 112, 0, r->img_bar);
	putimagePNG(750, 0, r->shovelSlot);
	putimagePNG(760, -10, r->shovel);
	for (int i = 0; i < 8;i++) {
		auto& a = type2[i];
		if (a->card_time++ >= a->card_speed&&a->card_indx<46) {
			a->card_time = 0;
			a->card_indx++;
		}
		putimagePNG(339 - 112 + i * 64, 8, r->img_card[a->type-1]);
		putimagePNG(339 - 112 + i * 64, 8, r->img_card_time[a->card_indx]);
		if (sun < a->cost) {
			putimagePNG(339 - 112 + i * 64, 8, r->img_card_load);
		}
	}
	for (auto&a:map) {
		for (auto&b:a) {
			if (b&&b->used) {
				b->show(r->img_zhiwu[b->type - 1]);
			}
		}
	}
	if (curPlant||chanzi) {
		
		IMAGE* img = curPlant ? r->img_zhiwu[curPlant->type - 1][0] : r->shovel;
		putimagePNG(curx - img->getwidth() / 2, cury - img->getheight() / 2, img);
	}
	for (auto& a : cars) {
		if (a.used) {
			putimagePNG(a.x, a.y, r->img_car);
		}
	}
	for (auto& a : zms) {
		if (a->used) {
			IMAGE* img1 = r->img_zm[a->type][a->img_indx];
			IMAGE* img2 = r->img_zm_dead[a->img_dead_indx];
			IMAGE* img3 = r->img_zm_bing[a->type][a->img_indx];
			if (a->status==ZM_DEAD) {
				putimagePNG(a->x, a->y, img2);
			}
			else {
				if (a->status == ZM_DAO) {
					putimagePNG(a->x, a->y, r->img_zm_head[a->img_head_indx]);
				}
				putimagePNG(a->x, a->y, a->isbing?img3:img1);
			}
		}
	}
	for (auto& a : bullets) {
		if (a.used) {
			IMAGE* img1 = r->img_bullet_normal;
			IMAGE* img2 = r->img_bullet_blast[a.img_indx];
			IMAGE* img3 = r->img_bullet_bing;
			IMAGE* img4 = r->img_bullet_huo;
			IMAGE* img5 = r->img_bullet_blast_bing[a.img_indx];
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
			else if (a.status == BULLET_BLAST_BING) {
				putimagePNG(a.x, a.y, img5);
			}
		}
	}
	for (auto& a : ball) {
		if (a.used) {
			IMAGE* img = r->img_sunshine[a.img_indx];
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
	maketype();
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

void Game::cardselectupdate()
{
	for (int i = 0; i < ZW_COUNT; i++) {
		putimagePNG(24 + i * 52, 131, r->img_card2[i]);
		if (type[i] != -1) { putimagePNG(75 + i * 55, 8, r->img_card2[type[i]]); }
	}
}

void Game::viewshow()
{
	int minx = WIN_WIDTH - r->img_bg->getwidth();
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
		putimage(x, 0, r->img_bg);
		count++;
		for (int i = 0; i < 9;i++) {
			putimagePNG(points[i].x - minx + x, points[i].y, r->img_zm_stand[indxs[i]]);
			if (count > 3) {
				indxs[i] = (indxs[i] + 1) % 11;
			}
		}
		if (count > 3) { count = 0; }
		EndBatchDraw();
		Sleep(5);
	}
	bool flag = false;
	int idx1 = -1, idx2 = -1;
	//选卡牌
	while(1) {
		BeginBatchDraw();
		putimage(minx, 0, r->img_bg);
		putimage(0, 0, r->img_selectbar);
		putimage(0, r->img_selectbar->getheight(), r->img_panelbg);
		cardselectupdate();
		if(flag){ putimage(157, 546, r->img_starbutton); }
		ExMessage msg;
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x > 75 && msg.x < 75 + 55 * ZW_COUNT && msg.y < 75 && msg.y>8) {
					idx1 = (msg.x - (75)) / 55;
				}
				else if (msg.x > 24 && msg.x < 24 + 52 * ZW_COUNT && msg.y < 75+131 && msg.y>131) {
					idx2 = (msg.x - (24)) / 52;
				}
			}
			if (msg.message == WM_LBUTTONUP) {
				if (idx1 != -1) {
					type[7] = -1;
					for (int i = idx1; i < 7; i++) {
						type[i] = type[i + 1];
					}
					idx1 = -1;
				}
				if (idx2 != -1) {
					int pos = -1;
					bool flag = true;
					for (int i = 0; i < 8;i++) {
						if (type[i] == -1 && pos == -1) { pos = i; }
						if (type[i] == idx2) { flag = false; }
					}
					if (flag) { type[pos] = idx2; }
					idx2 = -1;
				}
			}
			if (msg.message == WM_LBUTTONDOWN &&
				msg.x > 157 && msg.x < 157 + r->img_starbutton->getwidth() &&
				msg.y>546 && msg.y < 546 + r->img_starbutton->getheight()) {
				flag = true;
				mciSendString("play res/music/seedlift.mp3", 0, 0, 0);
			}
			if (msg.message == WM_LBUTTONUP && flag) {
				if (type[7] != -1) {
					EndBatchDraw();
					break;
				}
				else { flag = false; }
			}
		}
		count++;
		for (int i = 0; i < 9; i++) {
			putimagePNG(points[i].x, points[i].y, r->img_zm_stand[indxs[i]]);
			if (count > 10) {
				indxs[i] = (indxs[i] + 1) % 11;
			}
		}
		if (count > 10) { count = 0; }
		EndBatchDraw();
	}
	for (int x = minx; x <= -112; x += 2) {
		BeginBatchDraw();
		putimage(x, 0, r->img_bg);
		count++;
		for (int i = 0; i < 9; i++) {
			putimagePNG(points[i].x + x-minx, points[i].y, r->img_zm_stand[indxs[i]]);
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
	int height = r->img_bar->getheight();
	for (int y = -height; y <= 0; y++) {
		BeginBatchDraw();
		putimage(-112, 0, r->img_bg);
		putimagePNG(250 - 112, y, r->img_bar);
		for (int i = 0; i < ZW_COUNT; i++) {
			putimagePNG(339 - 112 + i * 64, y+8, r->img_card[type[i]]);
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
		a.p1 = vector2(260 + rand() % 540, 60);
		a.p4 = vector2(a.p1.x, 230 + (rand() % 4) * 90);
		a.t=0;
		float distance = dis(a.p1 - a.p4);
		float off = 5;
		a.speed = 1.0 / (distance / off);
	}
}

void Game::updateagme() {
	updatecar();
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
	bool flag = false;
	while (1) {
		BeginBatchDraw();
		putimage(0, 0, r->menu);
		putimagePNG(474, 75, flag ? r->menu1 : r->menu2);
		ExMessage msg;
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN &&
				msg.x > 474 && msg.x < 474 + 300 &&
				msg.y>75 && msg.y < 75 + 140) {
				flag = true;
			}
			if (msg.message == WM_LBUTTONUP && flag) {
				mciSendString("stop res/music/bg.mp3", 0, 0, 0);
				mciSendString("play res/music/UraniwaNi.mp3 repeat", 0, 0, 0);
				EndBatchDraw();
				break;
			}
		}
		EndBatchDraw();
	}
}

void Game::collectsun(ExMessage* msg){
	int w = r->img_sunshine[0]->getwidth();
	int h = r->img_sunshine[0]->getheight();
	for (auto& a : ball) {
		if (a.used) {
			int x = a.curp.x;
			int y = a.curp.y;
			if (msg->x > x && msg->x<x + w && msg->y>y && msg->y < y + h) {
				PlaySound(TEXT("res/music/sunshine.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
		fre = 100 + rand() % 100;
		int i = 0;
		while (zms[i]->used&&i < zms.size()) { i++; }
		if (i >= zms.size()) { return; }
		int ran = rand() % 4;
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

void Game::updatecar()
{
	for (auto& a : cars) {
		a.update();
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
			if (a.status==BULLET_BLAST||a.status==BULLET_BLAST_BING) {
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
		if (!b->used|| b->status==ZM_DEAD||b->status==ZM_DAO) { continue; }
		for (auto& a : bullets) {
			if (!a.used || a.status==BULLET_BLAST||a.status==BULLET_BLAST_BING) { continue; }
			int x1 = b->x + 80;
			int x2 = b->x + 110;
			int x = a.x;
			if (a.row == b->row && x > x1 && x < x2) {
				if (a.status == BULLET_BING&&!b->isbing) {
					mciSendString("play res/music/frozen.mp3", 0, 0, 0);
					b->isbing=true;
				}
				if(b->type==2){ PlaySound(TEXT("res/music/shieldhit.wav"), NULL, SND_FILENAME | SND_ASYNC); }
				else{ PlaySound(TEXT("res/music/splat2.wav"), NULL, SND_FILENAME | SND_ASYNC); }
				b->blood -= a.attack;
				a.dx = 0;
				a.status = a.status == BULLET_BING ? BULLET_BLAST_BING : BULLET_BLAST;
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
							mciSendString("play res/music/chompsoft.mp3", 0, 0, 0);
							if (count > 20) {
								count = 0;
								d->blood -= b->attack;
								mciSendString("play res/music/chomp.mp3", 0, 0, 0);
							}
						}
					}
					else {
						b->status = ZM_NORMAL;
					}
				}
			}
		}
		for (auto& a : cars) {
			if (a.used) {
				int x = b->x + 80;
				int x1 = a.x + 10;
				int x2 = a.x + 60;
				if (a.row == b->row && x > x1 && x < x2) {
					a.run = true;
					if (b->status != ZM_DEAD && b->status != ZM_DAO) {
						b->blood = -1;
					}
				}
			}
		}
	}
}

void Game::maketype()
{
	for (int i = 0; i < 8; i++) {
		type2[i] = getcurplant(i);
	}
}

void Game::userclick()
{
	ExMessage msg;
	static int status = 0;
	static int idx = 0;
	if (peekmessage(&msg)) {
		if (msg.message == WM_LBUTTONDOWN) {//鼠标按下
			if (msg.x > 227 && msg.x < 227 + 64 * ZW_COUNT && msg.y < 96 && msg.y>8) {
				idx = (msg.x - (227)) / 64;
				curPlant= getcurplant(idx);
				status = 1;
			}
			else if (msg.x>750&&msg.x<750+70&&msg.y<70&&msg.y>10) {
				chanzi = true;
				status = 1;
			}
			else {
				collectsun(&msg);
			}
		}
		else if (msg.message == WM_MOUSEMOVE&&status==1) {//鼠标拖动
			curx = msg.x, cury = msg.y;
		}
		else if (msg.message == WM_LBUTTONUP) {
			int x = msg.x;
			int y = msg.y;
			if (x > 144 && y > 77 && y < 591) {
				int row = (y - 77) / 102;
				int col = (x - 144) / 81;
				if (curPlant&&(!map[row][col] ||!map[row][col]->used) && status == 1 && sun >= curPlant->cost&& type2[idx]->card_indx==46) {
					curPlant->y = 77 + row * 102+curPlant->dy;
					curPlant->x = 144 + col * 81;
					curPlant->row = row;
					curPlant->col = col;
					curPlant->used = true;
					map[row][col] = curPlant;
					type2[idx]->card_indx = 0;
					sun -= map[row][col]->cost;
					PlaySound(TEXT("res/music/plant1.wav"), NULL, SND_FILENAME | SND_ASYNC);
					status = 0;
				}
				else if (chanzi && (map[row][col] && map[row][col]->used) && status == 1) {
					PlaySound(TEXT("res/music/plant2.wav"), NULL, SND_FILENAME | SND_ASYNC);
					map[row][col]->used = false;
				}
			}
			curPlant = NULL;
			chanzi = false;
		}
	}
}

plant* Game::getcurplant(int i)
{
	switch (type[i])
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