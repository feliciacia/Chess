//Position.h
#ifndef __POSITION_H__
#define __POSITION_H__
#include <iostream>

using namespace std;

struct Position
{
	int x;
	int y;
	Position() = default;
	Position(int x, int y) : x(x), y(y) {}
};

ostream& operator<<(ostream&, const Position&);
istream& operator>>(istream&, Position&);
#endif