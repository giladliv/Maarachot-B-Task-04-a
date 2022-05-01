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
    Game game{};
    
    Duke duke{game, "Gilad"};
    Assassin assassin{game, "Ido"};
    Ambassador ambassador{game, "Noa"};
    Captain captain{game, "Oleg"};
    Contessa contessa{game, "Nataly"};
    Assassin assassin2{game, "Perci"};

    for(int i = 0; i < 8; i++)
    {
        CHECK(duke.coins() == i);
        CHECK(assassin.coins() == i);
        CHECK(ambassador.coins() == i);
        CHECK(captain.coins() == i);
        CHECK(contessa.coins() == i);
        CHECK(assassin2.coins() == i);

        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
        assassin2.income();
    }

    duke.tax();
    assassin.coup(assassin2);
    CHECK(assassin.coins() == 5);
    CHECK_THROWS(assassin.foreign_aid());

    vector<string> players = game.players();
    CHECK(players.size() == 5);
    for (unsigned int i = 0; i < players.size(); i++)
    {
        CHECK(players[i] != "Perci");
    }

}