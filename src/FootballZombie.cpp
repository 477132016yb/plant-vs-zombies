//
// Created by yb on 2024/5/24.
//

#include "FootballZombie.h"
Zombie::ZombieType FootballZombie::s_type=ZombieType::FootballZombie;
FootballZombie::FootballZombie() {
    m_blood=600;
    m_speed=4;
    auto r=Singleton<res>::instanceSP();
    for(int i=0;i<m_atls.size()-1;i++){
        m_atls[i]=std::make_shared<Atlas>(r->atls_zombies[int(s_type)][i]);
    }
    m_atls[int(ZombieStatus::Ashes)]=std::make_shared<Atlas>(r->atl_zombieAshes);
    setStatus(Zombie::ZombieStatus::Walking);

    this->m_action->setLoop(true);
    this->m_action->setInterval(75);

}

Zombie::ZombieType FootballZombie::getType() {
    return s_type;
}
