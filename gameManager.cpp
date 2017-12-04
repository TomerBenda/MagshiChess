#include "gameManager.h"
const int PLAYER_INDEX = 64;

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
		src = new Position(move[0], move[1] - '0');
		dst = new Position(move[2], move[3] - '0');
	}
	catch (std::invalid_argument invalid_index)
	{
		return 5;
	}

	if (src == dst)
		return 7;

	// Checking if the source position has a piece that belongs to the current player.
	if (_curr !=  ('A' < _board[src->translate()]->getType() && _board[src->translate()]->getType() < 'Z'))
		return 2;

	if (_curr == ('a' < _board[dst->translate()]->getType() && _board[dst->translate()]->getType() < 'z'))
		return 3;

	//TODO: Check for cases 6 and 1: Legal move and if it is, if move causes Check on opponent.
	// If move is legal, eat opponent's piece if there is one.
	
	// King needs to run tests on other pieces to check for Check.

	return 0;

}
void gameManager::toggleCurrPlayer()
{
	_curr = !_curr;
}
void gameManager::logMessage(std::string msg)
{

}