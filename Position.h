#pragma once
#include <stdexcept>
#define SIDE_LEN 8

class Position
{
public:
	Position(char letter, int number);
	Position(int index);
	~Position();
	int translate() const;
	Position& operator=(const Position& other);
	bool operator==(const Position& other) const;
	char getLetter() const;
	int getNumber() const;
	int getIntLetter() const;

private:
	char _letter;
	int _number;
};

