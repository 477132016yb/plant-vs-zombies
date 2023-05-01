#pragma once
#include<iostream>
#include<easyx.h>
#include<vector>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#include"vector2.h"
#include"tools.h"
#include"plant.h"
#include"zm.h"
#include"bullet.h"
#include"sunshine.h"
#include"WDSS.h"
#include"XRK.h"
#include"HBSS.h"
#include"JGQ.h"
#include"TDDL.h"
#include"SRH.h"
#include"HJSZ.h"
#include"YTZD.h"
#include"lzzm.h"
#include"ttzm.h"
#include"glqzm.h"
#pragma comment(lib,"winmm.lib")
#define ZW_COUNT 8
#define ZM_COUNT 4
using namespace std;
class Game
{
public:
	Game();
	void init();
	void updatewindow();
	void play();
	void userclick();
	void startui();
	void viewshow();
	void bardown();
	plant* getcurplant(int i);
	bool checkfile(const char*name);
	void updateagme();
	void updateplant();
	void creatsunshine();
	void updatesunshine();
	void collectsun(ExMessage*msg);
	void creatzm();
	void updatezm();
	void updatebullet();
	void collisioncheck();
private:
	IMAGE *img_bg;//����ͼƬ
	IMAGE *img_bar;//���Ʋ�
	IMAGE *img_card[ZW_COUNT];//ֲ�￨��
	int curx,cury;//�϶������е�����
	plant* curPlant;//ѡ��ֲ��
	IMAGE* img_zhiwu[ZW_COUNT][30];//ֲ��ͼƬ
	vector<vector<plant*>>map;//ֲ��
	IMAGE* img_sunshine[29];//����ͼƬ
	vector<sunshine>ball;//�����
	int sun;//��������
	vector<zm*>zms;//��˿��
	vector<bullet>bullets;//�ӵ���
	IMAGE* img_bullet_normal;
	IMAGE* img_bullet_bing;
	IMAGE* img_bullet_huo;
	IMAGE* img_bullet_blast[4];

	IMAGE* img_zm[ZM_COUNT][50];//��˿ͼƬ

	IMAGE* img_zm_dead[20];
	IMAGE* img_zm_stand[11];
};