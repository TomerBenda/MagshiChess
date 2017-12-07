#pragma once
#include "Board.h"
#include "Player.h"
#include <vector>

class gameManager
{
public:
	gameManager(const std::string& str);
	~gameManager();
	
	std::string boardState();
	int makeTurn(std::string move);
	void toggleCurrPlayer();
	void logMessage(std::string msg);

private:
	Board _board;
	bool _curr;
	std::vector<Player> _players;
};

