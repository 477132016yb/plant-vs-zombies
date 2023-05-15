#pragma once
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#include"vector2.h"
#include"tools.h"
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
#include "res.h"
#pragma comment(lib,"winmm.lib")
class Game
{
public:
	Game();
	void init();
	void updatewindow();
	void play();
	void userclick();
	void startui();
	void cardselect();
	void viewshow();
	void bardown();
	plant* getcurplant(int i);
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
	res* r;//��Դ��
	int curx,cury;//�϶������е�����
	plant* curPlant;//ѡ��ֲ��
	vector<vector<plant*>>map;//ֲ��
	vector<sunshine>ball;//�����
	int sun;//��������
	vector<zm*>zms;//��˿��
	vector<bullet>bullets;//�ӵ���
	vector<int>type;//��������
};