#pragma once
#include<vector>
#include<easyx.h>
#include"bullet.h"
#include"zm.h"
#include"sunshine.h"
#include"tools.h"
#include<Windows.h>
#include<mmsystem.h>
//ֲ�����
using namespace std;
class plant
{
public:
	plant();
	int card_time;//������ȴ��ʱ
	int card_indx;//������ȴͼƬ���
	int card_speed;//������ȴ�ٶ�
	int img_indx;//ֲ��ͼƬ���
	int blood;//Ѫ��
	int timer;//ֲ�ﶯ��ˢ�¶�ʱ��
	int endtime;//ֲ�ﶯ��ˢ���ٶ�

	int type;//ֲ������
	int img_num;//ͼƬ����
	int cost;//���⻨��
	int attack;//������
	bool used;//�Ƿ���
	
	int x,y;//����
	int dy;//��ֱ����ƫ����
	int row,col;//������Ϣ
	virtual void show(IMAGE*img[]);//��ͼ
	virtual void update();//���ݸ���
	virtual void jineng(vector<bullet>&bullets, vector<zm*>&zms, vector<sunshine>& ball){};//����
};