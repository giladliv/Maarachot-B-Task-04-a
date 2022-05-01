#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace std;
using namespace coup;

TEST_CASE("Bad Amount and players")
{
    Game game{};
    
    Duke duke{game, "Gilad"};
    // one player
    CHECK_THROWS(duke.income());
    
    // Same name in game
    CHECK_THROWS(Duke(game, "Gilad"));
    CHECK_THROWS(Contessa(game, "Gilad"));

    Assassin assassin{game, "Ido"};
    Ambassador ambassador{game, "Noa"};
    Captain captain{game, "Oleg"};
    Contessa contessa{game, "Nataly"};

    Assassin assassin2{game, "Perci"};
    Ambassador ambassador2{game, "Hadar"};
    
    // 7 players
    CHECK_THROWS(duke.income());

}

TEST_CASE("Bad small game")
{
    Game game{};
    Captain captain{game, "Gilad"};
    Contessa contessa{game, "Hadar"};

    for (int i = 0; i < 10; i++)
    {
        captain.income();
        contessa.income();
    }

    // not players turn
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(contessa.foreign_aid());

    // must coup before
    CHECK_THROWS(captain.income());
    CHECK_THROWS(captain.coup(contessa));
    
    // cannot make move
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(contessa.foreign_aid());
}

TEST_CASE("Good coins round")
{
    
}