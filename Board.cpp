#include "Board.h"

Board::Board(const std::string& matrixStr) : _matrixStr(matrixStr)
{
	// This function is also responsible for creating the Players with their kings.
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

	delete _black;
	delete _white;
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
	bool moved = false;
	for (int i = 0; i < SIDE_LEN && !moved; i++)
	{
		for (int j = 0; j < SIDE_LEN && !moved; j++)
		{
			if (_pieces[i][j] != nullptr && _pieces[i][j]->getPos() == src)
			{
				_pieces[i][j]->move(dst);
				if (_pieces[dst.getLetter() - 'a'][dst.getNumber() - 1] != nullptr)
					delete _pieces[dst.getLetter() - 'a'][dst.getNumber() - 1];
				_pieces[dst.getLetter() - 'a'][dst.getNumber() - 1] = _pieces[i][j];
				_pieces[i][j] = nullptr;
				moved = true;
			}
		}
	}
	updateMatrixStr(src.translate(), dst.translate());
}
void Board::createPieces()
{
	for (unsigned int i = 0; i < _matrixStr.size(); i++)
	{
		Position p(i);
		King* newKing;
		switch (tolower(_matrixStr[i]))
		{
		case 'q':
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = new Queen(p, _matrixStr[i], this);
			break;
		case 'k':
			newKing = new King(p, _matrixStr[i], this);
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = newKing;
		
			if (_matrixStr[i] == 'k')
				_black = new Player(newKing, "Black");
			else
				_white = new Player(newKing, "White");
			break;
		case 'r':
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = new Rook(p, _matrixStr[i], this);
			break;
		case 'n':
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = new Knight(p, _matrixStr[i], this);
			break;
		case 'p':
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = new Pawn(p, _matrixStr[i], this);
			break;
		case 'b':
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = new Bishop(p, _matrixStr[i], this);
			break;
		default:
			_pieces[p.getLetter() - 'a'][p.getNumber() - 1] = nullptr;
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
	Position pos(index);
	return _pieces[pos.getLetter() - 'a'][pos.getNumber()-1];
}

Player* Board::getPlayer(bool player) const
{
	if (player)
		return _white;
	return _black;
}

void Board::updateMatrixStr(int oldIndex, int newIndex)
{
	//Updating the matrix string once a move has been made.
	_matrixStr[newIndex] = _matrixStr[oldIndex];
	_matrixStr[oldIndex] = '#';
}

Piece* Board::operator[](Position pos) const
{
	return (*this)[pos.translate()];
}

void Board::promote(Piece* promotion, const Position& old)
{
	_pieces[promotion->getPos().getLetter() - 'a'][promotion->getPos().getNumber() - 1] = promotion;
	_pieces[old.getLetter() - 'a'][old.getNumber() - 1] = nullptr;
	_matrixStr[promotion->getPos().translate()] = promotion->getType();
	_matrixStr[old.translate()] = '#';

	delete _pieces[old.getLetter() - 'a'][old.getNumber() - 1];
}