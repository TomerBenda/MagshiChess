#pragma once
#include <iostream>
#include "Position.h"
#include "King.h"

class King;

class Player
{
public:
	Player(King* playerKing, const std::string& name);
	~Player();
	King* getKing() const;
	void moveKing(Position dst);
	void setThreatened(const bool status);
	bool getThreatened();
private:
	std::string _name;
	King* _king;
	bool _isThreatened;
};

