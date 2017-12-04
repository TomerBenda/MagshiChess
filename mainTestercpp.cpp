#include <iostream>
#include <string>
#include "gameManager.h"
#include "Board.h"
#include "Piece.h"
int main()
{
	std::string start = "rk#####r################################################Rk#####R1";
	gameManager m(start);
	Position a('b', 1), b('a', 3), c('a',2);
	Board bo(start);
	Rook r(a,'r',&bo);
	bo.printState();
	King k(c, 'k', &bo);
	std::cout << "COMMAND a1b1 for r: " << r.checkMove(b) << std::endl;
	std::cout << "COMMAND a2b1 for r: " << k.checkMove(b) << std::endl;

	return 0;
}