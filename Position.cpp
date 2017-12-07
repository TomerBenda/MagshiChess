#include "Position.h"


Position::Position(char letter, int number)
{
	if ('a' > letter || 'h' < letter || number > 8 || number < 0)
		throw std::invalid_argument("Error: Position index out of range");

		_letter = letter;
		_number = number;
}
Position::Position(int index) 
{
	_number = index / SIDE_LEN; 
	_letter = char('a' + index % SIDE_LEN);
}
Position::~Position()
{
}

int Position::translate() const
{
	return _number * SIDE_LEN + (_letter - 'a');
}
Position& Position::operator=(const Position& other)
{
	_letter = other._letter;
	_number = other._number;

	return *this;
}
bool Position::operator==(const Position& other) const
{
	return translate() == other.translate();
}

char Position::getLetter() const
{
	return _letter;
}
int Position::getNumber() const
{
	return _number;
}
/**
A  B  C  D  E  F  G  H
0  1  2  3  4  5  6  7    0
8  9  10 11 12 13 14 15   1 
16 17 18 19 20 21 22 23   2
24 25 26 27 28 29 30 31   3
32 33 34                  4 */