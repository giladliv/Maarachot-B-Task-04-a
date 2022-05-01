#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Assassin : public Player
    {
    private:
        /* data */
    public:
        Assassin(Game& game, string name);
        ~Assassin();

        virtual void coup(const Player& player);
    };
    
    
}