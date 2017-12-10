#include "Player.h"

Player::Player(King* playerKing, const std::string& name) : _king(playerKing), _name(name), _isThreatened(false)
{
}
Player::~Player()
{

}

King* Player::getKing() const
{
	return _king;
}
void Player::moveKing(Position dst)
{
	_king->move(dst);
}

void Player::setThreatened(const bool status)
{
	_isThreatened = status;
}
bool Player::getThreatened() 
{
	return _isThreatened;
}