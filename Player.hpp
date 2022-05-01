#pragma once

#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;
using coup::Game;

namespace coup
{
    class Player
    {
        protected:
            int _coins;
            Game& _game;

        private:
            /* data */
            string _name;
            string _role;
        public:
            Player(Game& game, string name, string role = "");
            const string getName();
            ~Player();

            void income();
            void foreign_aid();
            virtual void coup(const Player& player);
            const string role();
            int coins();
    };
    
    
    
}