#include "Board.h"

Board::Board(const std::string& matrixStr) : _matrixStr(matrixStr)
{
	createPieces();
}

Board::~Board()
{
}

void Board::printState() const
{
	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			std::cout << _matrixStr[i * SIDE_LEN + j];
		}
	std::cout << std::endl;
	}
}
void Board::move(const Position& src, const Position& dst)
{
	for (Piece* p : _pieces)
	{
		if (p->getPos() == src)
			p->move(dst);
	}
}
void Board::createPieces()
{
	for (unsigned int i = 0; i < _matrixStr.size(); i++)
	{
		switch (tolower(_matrixStr[i]))
		{
		case 'q':
			//_pieces.push_back(new Queen(Position(i), _matrixStr[i], *this));
			break;
		case 'k':
			_pieces.push_back(new King(Position(i), _matrixStr[i], this));
			break;
		case 'r':
			_pieces.push_back(new Rook(Position(i), _matrixStr[i], this));
			break;
		case 'n':
			//_pieces.push_back(new Knight(Position(i), _matrixStr[i], *this));
			break;
		case 'p':
			//_pieces.push_back(new Pawn(Position(i), _matrixStr[i], *this));
			break;
		case 'b':
			//_pieces.push_back(new Bishop(Position(i), _matrixStr[i], *this));
			break;
		default:
			break;
		}
	}
}

std::string Board::getMatrixStr() const
{
	return _matrixStr;
}

char Board::operator[](int index) const
{
	return _matrixStr[index];
}