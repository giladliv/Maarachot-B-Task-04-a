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
        
    public:
        Game();
        ~Game();
        const string turn();
        const vector<string> players();
        const string winner();
    };
    
}