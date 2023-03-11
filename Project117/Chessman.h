#ifndef __CHESSMAN_H__
#define __CHESSMAN_H__
#include <iostream>
#include <map>
#include "Color.h"

using namespace std;

enum class Chessman {
	NONE,	//�L�Ѥl
	KING,	//���
	QUEEN,	//�ӦZ
	ROOK,	//����
	KNIGHT,	//�M�h
	BISHOP,	//�D��
	PAWN	//�h�L
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