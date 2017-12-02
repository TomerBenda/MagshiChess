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
	Position* src;
	Position* dst;
	// Checking if the 2 positions exist on the board
	try
	{
		src = new Position(move[0], int(move[1]));
		dst = new Position(move[2], int(move[3]));
	}
	catch (std::invalid_argument invalid_index)
	{
		return 5;
	}

	if (src == dst)
		return 7;

	// Checking if the source position has a piece that belongs to the current player.
	if (_curr &&  'A' < _board.getPiece(*src) < 'Z')
		return 2;

	if (_curr && !('a' < _board.getPiece(*dst) < 'z'))
		return 3;

}
void gameManager::toggleCurrPlayer()
{
	_curr = !_curr;
}
void gameManager::logMessage(std::string msg)
{

}