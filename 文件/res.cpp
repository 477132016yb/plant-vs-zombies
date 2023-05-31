#include "res.h"

void res::init()
{
	img_bg = new IMAGE;
	img_bar = new IMAGE;
	img_car = new IMAGE;
	img_card_load = new IMAGE;
	img_bullet_normal = new IMAGE;
	img_bullet_bing = new IMAGE;
	img_bullet_huo = new IMAGE;
	img_panelbg = new IMAGE;
	img_starbutton = new IMAGE;
	img_selectbar = new IMAGE;
	shovel = new IMAGE;
	shovelSlot = new IMAGE;
	menu = new IMAGE;
	menu1 = new IMAGE;
	menu2 = new IMAGE;
	
	for (int i = 0; i < 4; i++) {
		img_bullet_blast[i] = new IMAGE;
		img_bullet_blast_bing[i] = new IMAGE;
	}
	for (int i = 0; i < ZW_COUNT; i++) {
		img_card[i] = new IMAGE;
		img_card2[i] = new IMAGE;
		for (int j = 0; j < 40; j++) {
			img_zhiwu[i][j] = new IMAGE;
		}
	}
	for (int i = 0; i < 29; i++) {
		img_sunshine[i] = new IMAGE;
	}
	for (int i = 0; i < 47; i++) {
		img_card_time[i] = new IMAGE;
	}
	for (int i = 0; i < ZM_COUNT; i++) {
		for (int j = 0; j < 60; j++) {
			img_zm[i][j] = new IMAGE;
			img_zm_bing[i][j] = new IMAGE;
		}
	}
	for (int i = 0; i < 20; i++) {
		img_zm_dead[i] = new IMAGE;
	}
	for (int i = 0; i < 11; i++) {
		img_zm_stand[i] = new IMAGE;
	}
	for (int i = 0; i < 20; i++) {
		img_zm_head[i] = new IMAGE;
	}

	loadimage(img_bg, "res/imgs/bg.jpg");
	loadimage(img_car, "res/imgs/car.png");
	loadimage(img_bar, "res/imgs/bar5.png");
	loadimage(img_card_load, "res/imgs/card_load.png");
	loadimage(img_panelbg, "res/imgs/PanelBackground.png");
	loadimage(img_starbutton, "res/imgs/StartButton.png");
	loadimage(img_selectbar, "res/imgs/ChooserBackground.png");
	loadimage(img_bullet_normal, "res/imgs/bullets/bullet_normal.png");
	loadimage(img_bullet_bing, "res/imgs/bullets/bullet_bing.png");
	loadimage(img_bullet_huo, "res/imgs/bullets/bullet_huo.png");
	loadimage(shovel, "res/imgs/shovel.png");
	loadimage(shovelSlot, "res/imgs/shovelSlot.png");
	loadimage(menu, "res/imgs/menu.png");
	loadimage(menu1, "res/imgs/menu1.png");
	loadimage(menu2, "res/imgs/menu2.png");
	for (int i = 0; i < 4; i++) {
		float k = (i + 1) * 0.2;
		loadimage(img_bullet_blast[i], "res/imgs/bullets/bullet_blast.png",
			img_bullet_blast[i]->getwidth() * k, img_bullet_blast[i]->getheight() * k, true);
		loadimage(img_bullet_blast_bing[i], "res/imgs/bullets/bullet_blast_bing.png",
			img_bullet_blast_bing[i]->getwidth() * k, img_bullet_blast_bing[i]->getheight() * k, true);
	}
	char name[64];
	for (int i = 0; i < ZW_COUNT; i++) {
		sprintf_s(name, sizeof(name), "res/Cards/card_%d.png", i + 1);
		loadimage(img_card[i], name);
		loadimage(img_card2[i], name,52,70);
		int j = 0;
		while (1) {
			sprintf_s(name, sizeof(name), "res/zhiwu/%d/%d.png", i, j + 1);
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
	for (int i = 0; i < 47; i++) {
		sprintf_s(name, sizeof(name), "res/imgs/card_time/%d.png", i);
		loadimage(img_card_time[i], name);
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
		j = 0;
		while (1) {
			sprintf_s(name, sizeof(name), "res/zm_bing/%d/%d.png", i, j + 1);
			if (checkfile(name)) {
				loadimage(img_zm_bing[i][j], name);
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
	for (int i = 0; i < 20; i++) {
		sprintf_s(name, sizeof(name), "res/zm_head/%d.png", i + 1);
		loadimage(img_zm_head[i], name);
	}
}

bool res::checkfile(const char* name)
{
	FILE* fp = fopen(name, "r");
	if (fp) { fclose(fp); }
	return fp != NULL;
}

res* res::getres()
{
	if (m_res == NULL) {
		m_res = new res;
	}
	return m_res;
}
