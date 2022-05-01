#include "Player.hpp"

using coup::Player;

Player::Player(Game& game, string name, string role) : _game(game), _name(name), _role(role), _coins(0)
{
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

const string Player::role()
{
    return _role;
}

int Player::coins()
{
    return _coins;
}