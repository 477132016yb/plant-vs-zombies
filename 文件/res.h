#pragma once
#include<vector>
#include<easyx.h>
using namespace std;
#define ZW_COUNT 8
#define ZM_COUNT 4
//��Դ��
class res
{
public:
	void init();//ͼƬ��ʼ��
	bool checkfile(const char* name);//��ȡ�ļ��Ƿ����
	static res* m_res;//��Դ�൥��
	static res* getres();//��������
	IMAGE* img_car;//С�Ƴ�ͼƬ
	IMAGE* img_bg;//����ͼƬ
	IMAGE* img_bar;//���Ʋ�
	IMAGE* img_card_load;//������ȴ����ͼ
	IMAGE* img_card_time[47];//������ȴʱ��ͼ
	IMAGE* img_card[ZW_COUNT];//ֲ�￨��
	IMAGE* img_card2[ZW_COUNT];//ѡ��ʱ��ֲ�￨��
	IMAGE* img_zhiwu[ZW_COUNT][30];//ֲ��ͼƬ
	IMAGE* img_sunshine[29];//����ͼƬ
	IMAGE* img_bullet_normal;//�����㶹
	IMAGE* img_bullet_bing;//���㶹
	IMAGE* img_bullet_huo;//���㶹
	IMAGE* img_bullet_blast[4];//�㶹ը��ͼƬ
	IMAGE* img_bullet_blast_bing[4];//���㶹ը��ͼƬ
	IMAGE* img_zm[ZM_COUNT][60];//��˿ͼƬ
	IMAGE* img_zm_bing[ZM_COUNT][60];//������˿ͼƬ
	IMAGE* img_zm_dead[20];//��ʬ����ͼƬ
	IMAGE* img_zm_stand[11];//��ʬվ��ͼƬ
	IMAGE* img_zm_head[20];//��ʬ�Դ�ͼƬ
	IMAGE* img_panelbg;//ѡֲ�ﱳ��
	IMAGE* img_starbutton;//��ʼ��ť
	IMAGE* img_selectbar;//ֲ��ѡ�񿨲�
	IMAGE* shovel;//����
	IMAGE* shovelSlot;//�Ų��ӵ�
	IMAGE* menu;
	IMAGE* menu1;
	IMAGE* menu2;
private:
	res() {}
};