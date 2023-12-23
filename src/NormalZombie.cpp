//
// Created by yb on 2024/5/10.
//

#include "NormalZombie.h"
Zombie::ZombieType NormalZombie::s_type=ZombieType::NormalZombie;
NormalZombie::NormalZombie() {
    auto r=Singleton<res>::instanceSP();
    for(int i=0;i<m_atls.size()-1;i++){
        m_atls[i]=std::make_shared<Atlas>(r->atls_zombies[int(s_type)][i]);
    }
    m_atls[int(ZombieStatus::Ashes)]=std::make_shared<Atlas>(r->atl_zombieAshes);
    setStatus(Zombie::ZombieStatus::Walking);

    this->m_action->setLoop(true);
    this->m_action->setInterval(75);
}

Zombie::ZombieType NormalZombie::getType() {
    return s_type;
}
