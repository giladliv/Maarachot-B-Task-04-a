#include "Game.hpp"
using coup::Game;

Game::Game()
{
}

Game::~Game()
{
}

string Game::turn()
{
    return (_turn);
}

vector<string> Game::players()
{
    return(_players);
}

string Game::winner()
{
    return (_winner);
}