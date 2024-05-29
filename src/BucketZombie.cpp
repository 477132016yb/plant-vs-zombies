//
// Created by yb on 2024/5/24.
//

#include "BucketZombie.h"
Zombie::ZombieType BucketZombie::s_type=ZombieType::BucketZombie;
BucketZombie::BucketZombie() {
    m_blood=500;
    m_isArmor=true;
    auto r=Singleton<res>::instanceSP();
    for(int i=0;i<m_atls.size()-1;i++){
        m_atls[i]=std::make_shared<Atlas>(r->atls_zombies[int(s_type)][i]);
    }
    m_atls[int(ZombieStatus::Ashes)]=std::make_shared<Atlas>(r->atl_zombieAshes);
    setStatus(Zombie::ZombieStatus::Walking);

    this->m_action->setLoop(true);
    this->m_action->setInterval(175);
}

void BucketZombie::update(int delta) {
    Zombie::update(delta);
    if(m_blood<100&&m_isArmor){
        m_isArmor=false;
        auto r=Singleton<res>::instanceSP();
        for(int i=0;i<m_atls.size()-1;i++){
            m_atls[i]=std::make_shared<Atlas>(r->atls_zombies[0][i]);
        }
        setStatus(m_status);
    }
}

Zombie::ZombieType BucketZombie::getType() {
    return s_type;
}
