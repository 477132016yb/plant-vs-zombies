//
// Created by yb on 2024/4/29.
//

#include "res.h"
void res::init() {
    loadimage(&img_bg,"res/map/bg.jpg");
    loadimage(&img_menu,"res/map/menu.png");
    loadimage(&img_PanelBackGround,"res/map/PanelBackGround.png");
    loadimage(&img_gameBar,"res/imgs/gameBar.png");
    loadimage(&img_selectBar,"res/imgs/selectBar.png");
    loadimage(&img_shovel,"res/imgs/shovel.png");
    loadimage(&img_shovelSlot,"res/imgs/shovelSlot.png");
    loadimage(&img_bulletNormal,"res/imgs/bullets/Normal.png");
    loadimage(&img_bulletCool,"res/imgs/bullets/Cool.png");
    loadimage(&img_bulletFire,"res/imgs/bullets/Fire.png");
    loadimage(&img_PotatoMineUnderGround,"res/plant/PotatoMine/UnderGround.png");
    loadimage(&img_PotatoMineBoom,"res/plant/PotatoMine/Boom.png");
    loadimage(&img_car,"res/imgs/car.png");
    for (int i = 0; i < imgs_BlastNormal.size(); i++) {
        float k = (i + 1) * 0.2;
        loadimage(&imgs_BlastNormal[i], "res/imgs/bullets/bullet_blast.png",
                  imgs_BlastNormal[i].getwidth() * k, imgs_BlastNormal[i].getheight() * k, true);
        loadimage(&imgs_BlastCool[i], "res/imgs/bullets/bullet_blast_bing.png",
                  imgs_BlastCool[i].getwidth() * k, imgs_BlastCool[i].getheight() * k, true);
    }


    for(int i=0;i<imgs_startButton.size();i++){
        TCHAR path[64];
        sprintf_s(path,"res/map/start_%s.png",yb::buttonName[i]);
        loadimage(&imgs_startButton[i],path);
    }
    for(int i=0;i<imgs_fightButton.size();i++){
        TCHAR path[64];
        sprintf_s(path,"res/map/fight_%s.png",yb::buttonName[i]);
        loadimage(&imgs_fightButton[i],path);
    }

    for(int i=0;i<imgs_vriPlantVec.size();i++){
        TCHAR path[64];
        sprintf_s(path,"res/imgs/vritual/%d.png",i+1);
        loadimage(&imgs_vriPlantVec[i],path);
    }
    for(int i=0;i<imgs_selectCard.size();i++){
        TCHAR path[64];
        sprintf_s(path,"res/imgs/Cards/%d.png",i+1);
        loadimage(&imgs_selectCard[i],path,50,72);
        loadimage(&imgs_gameCard[i],path,60,85);
    }
    loadimage(&img_selectCardMask,"res/imgs/cardMask.png",50,72);
    loadimage(&img_gameCardMask,"res/imgs/cardLoad.png",60,85);

    for(int i=0;i<atls_plants.size();i++){
        TCHAR path[64];
        sprintf_s(path,"res/plant/%s",yb::plantNameList[i]);
        int num= getFileNum(path);
        atls_plants[i].loadFromFile(path,num);
    }
    atl_NutInjured.loadFromFile("res/plant/NutWall/Injured", getFileNum("res/plant/NutWall/Injured"));
    atl_NutNearDeath.loadFromFile("res/plant/NutWall/NearDeath", getFileNum("res/plant/NutWall/NearDeath"));
    atl_ChomperAttack.loadFromFile("res/plant/Chomper/Attack", getFileNum("res/plant/Chomper/Attack"));
    atl_ChomperDigestion.loadFromFile("res/plant/Chomper/Digestion", getFileNum("res/plant/Chomper/Digestion"));
    atl_CherryBoom.loadFromFile("res/plant/CherryBomb/Boom", getFileNum("res/plant/CherryBomb/Boom"));

    atl_sunShine.loadFromFile("res/sunshine",getFileNum("res/sunshine"));
    atl_cardCoolTime.loadFromFile2("res/imgs/cardCoolTime",getFileNum("res/imgs/cardCoolTime"));

    for(int i=0;i<atls_zombies.size();i++){
        for(int j=0;j<atls_zombies[i].size();j++){
            TCHAR path[64];
            sprintf_s(path,"res/zombie/%s/%s",yb::zombieNameList[i],yb::zombieStatusName[j]);
            int num = getFileNum(path);
            atls_zombies[i][j].loadFromFile(path,num);
        }
    }
    atl_zombieAshes.loadFromFile("res/zombie/Ashes", getFileNum("res/zombie/Ashes"));
    atl_zombieHead.loadFromFile("res/zombie/Head", getFileNum("res/zombie/Head"));
}

bool res::checkfile(const char *name) {
    FILE* fp = fopen(name, "r");
    if (fp) { fclose(fp); }
    return fp != NULL;
}

res::res() {
    atls_plants.resize(PLANT_COUNT);
    atls_zombies=std::vector<std::vector<Atlas>>(ZOMBIE_COUNT,std::vector<Atlas>(yb::zombieStatusName.size()));
    imgs_startButton.resize(3);
    imgs_fightButton.resize(3);
    imgs_selectCard.resize(getFileNum("res/imgs/Cards/"));
    imgs_gameCard.resize(getFileNum("res/imgs/Cards/"));
    imgs_vriPlantVec.resize(getFileNum("res/imgs/vritual"));
    imgs_BlastCool.resize(4);
    imgs_BlastNormal.resize(4);
    init();
}

int res::getFileNum(const char *filePath) {
    int num=0;
    char name[64];
    while(true){
        sprintf_s(name, "%s/%d.png", filePath,num+1);
        if (checkfile(name)) {
            num++;
        }
        else { break; }
    }
    return num;
}
