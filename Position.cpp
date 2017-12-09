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

/* A   B   C   D   E   F   G   H
8  0   1   2   3   4   5   6   7
7  8   9   10  11  12  13  14  15
6  16  17  18  19  20  21  22  23
5  24  25  26  27  28  29  30  31
4  32  33  34  35  36  37  38  39
3  40  41  42  43  44  45  46  47
2  48  49  50  51  52  53  54  55
1  56  57  58  59  60  61  62  63


*/