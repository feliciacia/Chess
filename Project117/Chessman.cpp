//Chessman.cpp
#include "Chessman.h"
#include <map>

ostream& operator<<(ostream& os, const ColeredChessman& c) {
	map<Chessman, string> chessman_string{
			{ Chessman::NONE, "None" },		//無棋子
			{ Chessman::KING, "King" },		//國王
			{ Chessman::QUEEN, "Queen" },	//皇后
			{ Chessman::ROOK, "Rook" },		//城堡
			{ Chessman::KNIGHT, "Knight" },	//騎士
			{ Chessman::BISHOP, "Bishop" },	//主教
			{ Chessman::PAWN, "Pawn" }		//士兵
	};
	map<Color, string> color_string{
		{ Color::NONE, "None" },		//無
		{ Color::BLACK, "Black" },		//黑
		{ Color::WHITE, "White" }		//白
	};
	os << chessman_string[c.chessman] << "(" << color_string[c.color] << ")";
	return os;
}