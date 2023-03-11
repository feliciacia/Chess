//Position.cpp
#include "Position.h"

ostream& operator<<(ostream& os, const Position& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
istream& operator>>(istream& is, Position& p) {
	is >> p.x >> p.y;
	return is;
}