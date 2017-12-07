#include "Board.h"

Board::Board(const std::string& matrixStr) : _matrixStr(matrixStr)
{
	createPieces();
}

Board::~Board()
{
	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			delete _pieces[i][j];
		}
	}
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
	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			if (_pieces[i][j]->getPos() == src)
				_pieces[i][j]->move(dst);
		}
	}
}
void Board::createPieces()
{
	for (unsigned int i = 0; i < _matrixStr.size(); i++)
	{
		King* newKing;
		Position p(i);
		switch (tolower(_matrixStr[i]))
		{
		case 'q':
			//_pieces[p.getLetter() - 'a'][p.getNumber()](new Queen(p, _matrixStr[i], this));
			break;
		case 'k':
			newKing = new King(p, _matrixStr[i], this);
			_pieces[p.getLetter() - 'a'][p.getNumber()] = newKing;

			if ( _matrixStr[i] = 'k')
				_kingB = newKing;
			else
				_kingW = newKing;
			break;
		case 'r':
			_pieces[p.getLetter() - 'a'][p.getNumber()] = new Rook(p, _matrixStr[i], this);
			break;
		case 'n':
			//_pieces[p.getLetter() - 'a'][p.getNumber()] = new Knight(p, _matrixStr[i], this);
			break;
		case 'p':
			//_pieces[p.getLetter() - 'a'][p.getNumber()] = new Pawn(p, _matrixStr[i], this);
			break;
		case 'b':
			//_pieces[p.getLetter() - 'a'][p.getNumber()] = new Bishop(p, _matrixStr[i], this);
			break;
		default:
			_pieces[p.getLetter() - 'a'][p.getNumber()] = NULL;
			break;
		}
	}
}

std::string Board::getMatrixStr() const
{
	return _matrixStr;
}

Piece* Board::operator[](int index) const
{
	Position tmp(index);
	return _pieces[tmp.getLetter() - 'a'][tmp.getNumber()];
}

King* Board::getKing(char c) const
{
	if ('a' < c && c < 'z')
		return _kingB;
	else
		return _kingW;
}