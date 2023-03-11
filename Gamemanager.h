#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Viewer.h"
#include <vector>
using namespace std;

class GameManager 
{
public:
	Player* players[2];
	int current_player = 0;
	Color color;
	Board board;
	vector<string>moveset;
	vector<ColeredChessman>piecetaken;
	GameManager() : color(Color::WHITE)  {}
	int roundnum = 0;
	bool moveKing(ColeredChessman* thisKing, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]);
	bool moveQueen(ColeredChessman* thisQueen, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]);
	bool moveBishop(ColeredChessman* thisBishop, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]);
	bool moveKnight(ColeredChessman* thisKnight, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]);
	bool moveRook(ColeredChessman* thisRook, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]);
	bool movePawn(ColeredChessman* thisPawn, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]);
	bool moveIt();
	bool isCheck(ColeredChessman checkerboard[8][8]);
	bool isValid(int x1, int y1, int x2, int y2);
	bool isCMorSM();
	bool undo();
	bool redo();
	Position findChessman(Chessman chessman, Color , ColeredChessman checkerboard[8][8]);
};
#endif