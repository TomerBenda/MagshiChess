#include "Position.h"


Position::Position(char letter, int number)
{
	if ('a' > letter || 'h' <= letter || number > 8 || number <= 0)
		throw std::invalid_argument("Nope!");

		_letter = letter;
		_number = number - 1;
}
Position::Position(int index)
{
	_number = index % SIDE_LEN;
	_letter = char('a' + index / 8);
}
Position::~Position()
{
}

int Position::translate()
{
	return (_letter - 'a') * SIDE_LEN + _number;
}
Position& Position::operator=(const Position& other)
{
	_letter = other._letter;
	_number = other._number;

	return *this;
}
bool Position::operator==(const Position& other)
{
	return _letter = other._letter && _number == other._number;
}

char Position::getLetter() const
{
	return _letter;
}
int Position::getNumber() const
{
	return _number;
}