#include <iostream>
#include <string>
#include "gameManager.h"
#include "Board.h"
#include "Piece.h"
int testmain()
{
	std::string start = "r######rr########k##########K###########################R######R1";
	gameManager m(start);
	// Checking movement.
	std::cout << "Board before testing:" << std::endl;
	m.printState();
	// Moving Rook to threaten enemy king. Legal move, returns 1.
	std::cout << "A1E1: " << m.makeTurn("a1e1") << std::endl;
	// Moving King to a place that does not move him from Check. Illegal move for king, returns 6.
	std::cout << "e4e5: " << m.makeTurn("e4e5") << std::endl;
	// Moving King out of Check.
	std::cout << "e4d4: " << m.makeTurn("e4d4") << std::endl;
	// Moving Rook to an illegal location. Illegal move, returns 2.
	std::cout << "A2A3: " << m.makeTurn("a1a3") << std::endl;
	// Moving Rook to a legal position. Legal move, returns 0.
	std::cout << "A2A6: " << m.makeTurn("a2a6") << std::endl;
	
	std::cout << "Board after changes:" << std::endl;
	m.printState();
	return 0;
}