#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace coup
{
    class Game
    {
    private:
        /* data */
        string _turn;
        vector<string> _players;
        string _winner;
        
    public:
        Game();
        ~Game();
        string turn();
        vector<string> players();
        string winner();
    };
    
}