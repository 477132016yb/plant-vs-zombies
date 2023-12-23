//
// Created by yb on 2024/5/24.
//

#include "CherryBomb.h"
#include "ObjManager.h"
plant::plantType CherryBomb::s_type=plantType::CherryBomb;
CherryBomb::CherryBomb() {
    m_damage=2500;
    Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atls_plants[int(s_type)]);
    this->m_action->setAtlas(atlas);
    this->m_action->setLoop(false);
    this->m_action->setInterval(100);
    this->m_action->setCallback([this](){
        Boom();
        m_action->reset();
        Atlas ::SP atlas=std::make_shared<Atlas>(Singleton<res>::instanceSP()->atl_CherryBoom);
        m_action->setAtlas(atlas);
        m_action->setCallback([this](){
            m_used=false;
        });
    });
}

plant::plantType CherryBomb::getType() {
    return s_type;
}

void CherryBomb::skills(int delta) {
    plant::skills(delta);
}

void CherryBomb::Boom() {
    for(int i=-1;i<2;i++){
        int row =m_row+i;
        if(row<0||row>4){ continue;}
        auto &v=Singleton<ObjManager>::instanceSP()->getZombies(row);
        for(auto&a:v){
            if(a->m_col>=m_col-1&&a->m_col<=m_col+1){
                a->m_blood-=m_damage;
                mciSendString("play res/music/cherrybomb.mp3", 0, 0, 0);
            }
        }
    }
}
