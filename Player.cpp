#include "Player.hpp"

using coup::Player;

Player::Player(Game& game, const string& name, const string& role) : _game(game), _coins(0)
{
    _name = name;
    _role = role;
}

Player::~Player()
{
}

void Player::income()
{

}

void Player::foreign_aid()
{

}

void Player::coup(const Player& player)
{

}

string Player::role() const
{
    return _role;
}

int Player::coins() const
{
    return _coins;
}