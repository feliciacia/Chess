#ifndef __CHESSMAN_H__
#define __CHESSMAN_H__
#include <iostream>
#include <map>
#include "Color.h"

using namespace std;

enum class Chessman {
	NONE,	//無棋子
	KING,	//國王
	QUEEN,	//皇后
	ROOK,	//城堡
	KNIGHT,	//騎士
	BISHOP,	//主教
	PAWN	//士兵
};

struct ColeredChessman {
	Chessman chessman;
	Color color;
	ColeredChessman() : chessman(Chessman::NONE), color(Color::NONE) {}
	ColeredChessman(int x, int y) : chessman(Chessman::NONE), color(Color::NONE), x(x), y(y) {}
	ColeredChessman(Chessman m, Color c, int x, int y) : chessman(m), color(c), x(x), y(y) {}
	int x, y;
};

ostream& operator<<(ostream& os, const ColeredChessman& c);
#endif // !__CHESSMAN_H__