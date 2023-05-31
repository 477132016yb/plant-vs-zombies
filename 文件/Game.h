#pragma once
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#include<thread>
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
#include"res.h"
#include"car.h"
#pragma comment(lib,"winmm.lib")
class Game
{
public:
	Game();
	void init();//��ʼ��
	void updatewindow();//���´���
	void play();//��ʼ��Ϸ
	void userclick();//�����Ϣ����
	void startui();//��ʼ����
	void cardselectupdate();//����ѡ��ʱ�Ľ���ˢ��
	void viewshow();//չʾ����������ѡ��
	void bardown();//������������
	plant* getcurplant(int i);//��ȡ��ǰѡ��ֲ������
	void updateagme();//������Ϸ����
	void updateplant();//����ֲ��
	void creatsunshine();//��������
	void updatesunshine();//��������
	void collectsun(ExMessage*msg);//�ռ�����
	void creatzm();//������ʬ
	void updatezm();//���½�ʬ
	void updatecar();//���³�
	void updatebullet();//�����ӵ�
	void collisioncheck();//��ײ���
	void maketype();//���ɿ��۶�Ӧ��ֲ����
private:
	res* r;//��Դ��
	int curx,cury;//�϶������е�����
	bool chanzi;//�Ƿ�ѡ�в���
	plant* curPlant;//ѡ��ֲ��
	vector<vector<plant*>>map;//ֲ��
	vector<sunshine>ball;//�����
	int sun;//��������
	vector<zm*>zms;//��˿��
	vector<bullet>bullets;//�ӵ���
	vector<int>type;//��������
	vector<plant*>type2;//����ֲ��
	vector<car>cars;//С�Ƴ�
};