#include "Game.h"
int main() {
    Game a;
    try{
        a.play();
    }
    catch (std::exception& e){
        LOG(e.what());
    }
}
