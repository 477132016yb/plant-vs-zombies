#pragma once
#include<vector>
#include<easyx.h>
using namespace std;
#define ZW_COUNT 8
#define ZM_COUNT 4
//资源类
class res
{
public:
	void init();//图片初始化
	bool checkfile(const char* name);//读取文件是否存在
	static res* m_res;//资源类单例
	static res* getres();//创建单例
	IMAGE* img_car;//小推车图片
	IMAGE* img_bg;//背景图片
	IMAGE* img_bar;//卡牌槽
	IMAGE* img_card_load;//卡牌冷却背景图
	IMAGE* img_card_time[47];//卡牌冷却时间图
	IMAGE* img_card[ZW_COUNT];//植物卡牌
	IMAGE* img_card2[ZW_COUNT];//选择时的植物卡牌
	IMAGE* img_zhiwu[ZW_COUNT][30];//植物图片
	IMAGE* img_sunshine[29];//阳光图片
	IMAGE* img_bullet_normal;//正常豌豆
	IMAGE* img_bullet_bing;//冰豌豆
	IMAGE* img_bullet_huo;//火豌豆
	IMAGE* img_bullet_blast[4];//豌豆炸裂图片
	IMAGE* img_bullet_blast_bing[4];//冰豌豆炸裂图片
	IMAGE* img_zm[ZM_COUNT][60];//姜丝图片
	IMAGE* img_zm_bing[ZM_COUNT][60];//冰冻姜丝图片
	IMAGE* img_zm_dead[20];//僵尸死亡图片
	IMAGE* img_zm_stand[11];//僵尸站立图片
	IMAGE* img_zm_head[20];//僵尸脑袋图片
	IMAGE* img_panelbg;//选植物背景
	IMAGE* img_starbutton;//开始按钮
	IMAGE* img_selectbar;//植物选择卡槽
	IMAGE* shovel;//铲子
	IMAGE* shovelSlot;//放铲子的
	IMAGE* menu;
	IMAGE* menu1;
	IMAGE* menu2;
private:
	res() {}
};