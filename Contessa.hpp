#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Contessa : public Player
    {
    private:
        /* data */
    public:
        Contessa(Game& game, string name);
        ~Contessa();
        void block(Player& Player);
    };
    
    
}