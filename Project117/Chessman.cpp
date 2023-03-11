//Chessman.cpp
#include "Chessman.h"
#include <map>

ostream& operator<<(ostream& os, const ColeredChessman& c) {
	map<Chessman, string> chessman_string{
			{ Chessman::NONE, "None" },		//�L�Ѥl
			{ Chessman::KING, "King" },		//���
			{ Chessman::QUEEN, "Queen" },	//�ӦZ
			{ Chessman::ROOK, "Rook" },		//����
			{ Chessman::KNIGHT, "Knight" },	//�M�h
			{ Chessman::BISHOP, "Bishop" },	//�D��
			{ Chessman::PAWN, "Pawn" }		//�h�L
	};
	map<Color, string> color_string{
		{ Color::NONE, "None" },		//�L
		{ Color::BLACK, "Black" },		//��
		{ Color::WHITE, "White" }		//��
	};
	os << chessman_string[c.chessman] << "(" << color_string[c.color] << ")";
	return os;
}