#pragma once
#include <iostream>
#include "Position.h"

class Player
{
public:
	Player(const std::string& name);
	~Player();
	Position getKing() const;
	void moveKing(Position dst);

private:
	std::string _name;
	Position _king;
	bool _isThreatened;
};

