//
// Created by yb on 2024/5/7.
//
#include "const.h"
namespace yb{
    bool checkHit(int x, int y, int objX, int objy, int objW, int objH) {
        return x>objX&&x<objX+objW&&y>objy&&y<objy+objH;
    }
    bool checkHitX(int x,int objX,int objW){
        return x>objX&&x<objX+objW;
    }
    std::vector<int> plantCostList = {100,50,175,50,25,150,125,150};
    std::vector<int> plantCoolTimeList = {75,100,125,100,300,100,75,50};
    std::vector<const char*>plantNameList={
    "PeaShooter","SunFlower","SnowPea","NutWall","PotatoMine","Chomper","TorchWood","CherryBomb"
    };
    std::vector<const char*>zombieNameList={
            "NormalZombie","RoadBlockZombie","BucketZombie","FootballZombie"
    };
    std::vector<const char*>buttonName{
        "idle","hovered","pushed"
    };
    std::vector<const char*>zombieStatusName{
            "Stand","Walking","Attack","FallDown"
    };
}
