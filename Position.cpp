#include "Position.h"


Position::Position(char letter, int number)
{
	if ('a' > letter || 'h' < letter || number > 8 || number < 0)
		throw std::invalid_argument("Error: Position index out of range");

		_letter = letter;
		_number = number;
}
Position::Position(int index) //B6 = 17
{
	_number = SIDE_LEN - (index / SIDE_LEN); 
	_letter = char('a' + index % SIDE_LEN);
}
Position::~Position()
{
}

int Position::translate() const
{
	return (SIDE_LEN -_number) * SIDE_LEN + (_letter - 'a');
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
int Position::getIntLetter() const
{
	return _letter - 'a';
}

/* A   B   C   D   E   F   G   H
8  0   1   2   3   4   5   6   7
7  8   9   10  11  12  13  14  15
6  16  17 
5
4
3
2
1


*/