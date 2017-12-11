#include "Position.h"


Position::Position(char letter, int number)
{
	if ('a' > letter || 'h' < letter || number > 8 || number <= 0)
		throw std::invalid_argument("Error: Position index out of range");

		_letter = letter;
		_number = number - 1;
}
Position::Position(int index)
{
	_number = SIDE_LEN - (index / SIDE_LEN) -1; 
	_letter = char('a' + index % SIDE_LEN);
}
Position::~Position()
{
}

int Position::translate() const
{
	return (SIDE_LEN - _number - 1) * SIDE_LEN + (_letter - 'a');
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