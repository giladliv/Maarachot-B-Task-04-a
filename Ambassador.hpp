#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Ambassador : public Player
    {
    private:
        /* data */
    public:
        Ambassador(Game& game, string name);
        ~Ambassador();
        void transfer(Player& srcPlyr, Player& dstPlyr);
    };
    
    
}