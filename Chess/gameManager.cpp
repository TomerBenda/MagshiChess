#include "gameManager.h"
const int PLAYER_INDEX = 65;

gameManager::gameManager(const std::string& str) : _board(str.substr(0, 64)), _curr(str[PLAYER_INDEX] == 0)
{
}

gameManager::~gameManager()
{
}

std::string gameManager::boardState()
{
	return _board.getMatrixStr();
}
int gameManager::makeTurn(std::string move)
{

}
void gameManager::toggleCurrPlayer()
{
	_curr = !_curr;
}
void gameManager::logMessage(std::string msg)
{

}