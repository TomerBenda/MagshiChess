#pragma once
#include <stdexcept>
const int SIDE_LEN = 8;

class Position
{
public:
	Position(char letter, int number);
	Position(int index);
	~Position();
	int translate();
	Position& operator=(const Position& other);
	bool operator==(const Position& other);
	char getLetter() const;
	int getNumber() const;

private:
	char _letter;
	int _number;
};

