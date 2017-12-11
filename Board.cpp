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
	_pieces[src.getNumber()][src.getIntLetter()]->move(dst);
	if (_pieces[dst.getNumber()][dst.getIntLetter()] != nullptr)
		delete _pieces[dst.getNumber()][dst.getIntLetter()];
	_pieces[dst.getNumber()][dst.getIntLetter()] = _pieces[src.getNumber()][src.getIntLetter()];
	_pieces[src.getNumber()][src.getIntLetter()] = nullptr;
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
			_pieces[p.getNumber()][p.getIntLetter()] = new Queen(p, _matrixStr[i], this);
			break;
		case 'k':
			newKing = new King(p, _matrixStr[i], this);
			_pieces[p.getNumber()][p.getIntLetter()] = newKing;
		
			if (_matrixStr[i] == 'k')
				_black = new Player(newKing, "Black");
			else
				_white = new Player(newKing, "White");
			break;
		case 'r':
			_pieces[p.getNumber()][p.getIntLetter()] = new Rook(p, _matrixStr[i], this);
			break;
		case 'n':
			_pieces[p.getNumber()][p.getIntLetter()] = new Knight(p, _matrixStr[i], this);
			break;
		case 'p':
			_pieces[p.getNumber()][p.getIntLetter()] = new Pawn(p, _matrixStr[i], this);
			break;
		case 'b':
			_pieces[p.getNumber()][p.getIntLetter()] = new Bishop(p, _matrixStr[i], this);
			break;
		default:
			_pieces[p.getNumber()][p.getIntLetter()] = nullptr;
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
	return (*this)[pos];
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

Piece* Board::getPiece(const Position& src)
{
	Piece* p = _pieces[src.getNumber()][src.getIntLetter()];
	_pieces[src.getNumber()][src.getIntLetter()] = nullptr;
	return p;
}

Piece* Board::operator[](Position pos) const
{
	return _pieces[pos.getNumber()][pos.getIntLetter()];
}
void Board::changePiece(Piece* newPiece, const Position& pos)
{
	_pieces[pos.getIntLetter()][pos.getNumber()] = newPiece;
	_matrixStr[pos.translate()] = newPiece->getType();
}
void Board::promote(Piece* promotion, const Position& old)
{
	_pieces[promotion->getPos().getIntLetter()][promotion->getPos().getNumber()] = promotion;
	_pieces[old.getIntLetter()][old.getNumber()] = nullptr;
	_matrixStr[promotion->getPos().translate()] = promotion->getType();
	_matrixStr[old.translate()] = '#';

	delete _pieces[old.getIntLetter()][old.getNumber()];
}