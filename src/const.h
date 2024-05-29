//
// Created by yb on 2024/4/28.
//

#ifndef PVZ_CONST_H
#define PVZ_CONST_H
#include <iostream>
#include <vector>
#define WIN_WIDTH 900
#define WIN_HEIGHT 600
#define FPS 90
#define LOG(a) std::cout<<a<<std::endl
#define PLANT_COUNT yb::plantNameList.size()
#define ZOMBIE_COUNT yb::zombieNameList.size()
typedef unsigned long long uint64_t;
namespace yb {
    extern std::vector<int>plantCoolTimeList;
    extern std::vector<int>plantCostList;
    extern std::vector<const char*>plantNameList;
    extern std::vector<const char*>zombieNameList;
    extern std::vector<const char*>buttonName;
    extern std::vector<const char*>zombieStatusName;

    bool checkHit(int x,int y,int objX,int objy,int objW,int objH);
    bool checkHitX(int x,int objX,int objW);

    template<typename T>
    void clearVector(std::vector<T*>&vec){
        for(T*& a:vec){
            if(a&&!a->m_used){
                delete a;
                a= nullptr;
                std::swap(a,vec.back());
                vec.pop_back();
            }
        }
    }

    template<typename T>
    void updateVector(std::vector<T*>&vec,int delta){
        for(T*& a:vec){
            if(a){
                a->update(delta);
            }
        }
    }


    template<typename T>
    void drawVector(std::vector<T*>&vec){
        for(T*& a:vec){
            if(a){
                a->draw();
            }
        }
    }
}
#endif //PVZ_CONST_H
