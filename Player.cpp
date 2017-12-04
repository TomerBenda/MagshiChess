#include "Player.h"

Player::Player(const std::string& name) : _king(0), _name(name), _isThreatened(false)
{
}
Player::~Player()
{

}

Position Player::getKing() const
{
	return _king;
}
void Player::moveKing(Position dst)
{
	_king = dst;
}