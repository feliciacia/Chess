#include "Board.h"

Board::Board() {
	for (int i = 2; i < 7; i++) {
		for (int j = 0; j < 8; j++)
			checkerboard[i][j] = ColeredChessman(Chessman::NONE, Color::NONE, i, j);
	}
	checkerboard[0][0] = ColeredChessman(Chessman::ROOK, Color::BLACK, 0, 0);
	checkerboard[0][7] = ColeredChessman(Chessman::ROOK, Color::BLACK, 0, 7);
	checkerboard[7][0] = ColeredChessman(Chessman::ROOK, Color::WHITE, 7, 0);
	checkerboard[7][7] = ColeredChessman(Chessman::ROOK, Color::WHITE, 7, 7);

	checkerboard[0][1] = ColeredChessman(Chessman::KNIGHT, Color::BLACK, 0, 1);
	checkerboard[0][6] = ColeredChessman(Chessman::KNIGHT, Color::BLACK, 0, 6);
	checkerboard[7][1] = ColeredChessman(Chessman::KNIGHT, Color::WHITE, 7, 1);
	checkerboard[7][6] = ColeredChessman(Chessman::KNIGHT, Color::WHITE, 7, 6);

	checkerboard[0][2] = ColeredChessman(Chessman::BISHOP, Color::BLACK, 0, 2);
	checkerboard[0][5] = ColeredChessman(Chessman::BISHOP, Color::BLACK, 0, 5);
	checkerboard[7][2] = ColeredChessman(Chessman::BISHOP, Color::WHITE, 7, 2);
	checkerboard[7][5] = ColeredChessman(Chessman::BISHOP, Color::WHITE, 7, 5);

	checkerboard[0][4] = ColeredChessman(Chessman::KING, Color::BLACK, 0, 4);
	checkerboard[0][3] = ColeredChessman(Chessman::QUEEN, Color::BLACK, 0, 3);
	checkerboard[7][4] = ColeredChessman(Chessman::KING, Color::WHITE, 7, 4);
	checkerboard[7][3] = ColeredChessman(Chessman::QUEEN, Color::WHITE, 7, 3);

	for (int j = 0; j < 8; j++)
		checkerboard[1][j] = ColeredChessman(Chessman::PAWN, Color::BLACK, 1, j);

	for (int j = 0; j < 8; j++)
		checkerboard[6][j] = ColeredChessman(Chessman::PAWN, Color::WHITE, 6, j);
}

void Board::reset() {
	for (int i = 2; i < 7; i++) {
		for (int j = 0; j < 8; j++)
			checkerboard[i][j] = ColeredChessman(Chessman::NONE, Color::NONE, i, j);
	}
	checkerboard[0][0] = ColeredChessman(Chessman::ROOK, Color::BLACK, 0, 0);
	checkerboard[0][7] = ColeredChessman(Chessman::ROOK, Color::BLACK, 0, 7);
	checkerboard[7][0] = ColeredChessman(Chessman::ROOK, Color::WHITE, 7, 0);
	checkerboard[7][7] = ColeredChessman(Chessman::ROOK, Color::WHITE, 7, 7);

	checkerboard[0][1] = ColeredChessman(Chessman::KNIGHT, Color::BLACK, 0, 1);
	checkerboard[0][6] = ColeredChessman(Chessman::KNIGHT, Color::BLACK, 0, 6);
	checkerboard[7][1] = ColeredChessman(Chessman::KNIGHT, Color::WHITE, 7, 1);
	checkerboard[7][6] = ColeredChessman(Chessman::KNIGHT, Color::WHITE, 7, 6);

	checkerboard[0][2] = ColeredChessman(Chessman::BISHOP, Color::BLACK, 0, 2);
	checkerboard[0][5] = ColeredChessman(Chessman::BISHOP, Color::BLACK, 0, 5);
	checkerboard[7][2] = ColeredChessman(Chessman::BISHOP, Color::WHITE, 7, 2);
	checkerboard[7][5] = ColeredChessman(Chessman::BISHOP, Color::WHITE, 7, 5);

	checkerboard[0][3] = ColeredChessman(Chessman::KING, Color::BLACK, 0, 3);
	checkerboard[0][4] = ColeredChessman(Chessman::QUEEN, Color::BLACK, 0, 4);
	checkerboard[7][3] = ColeredChessman(Chessman::KING, Color::WHITE, 7, 3);
	checkerboard[7][4] = ColeredChessman(Chessman::QUEEN, Color::WHITE, 7, 4);

	for (int j = 0; j < 8; j++)
		checkerboard[1][j] = ColeredChessman(Chessman::PAWN, Color::BLACK, 1, j);

	for (int j = 0; j < 8; j++)
		checkerboard[6][j] = ColeredChessman(Chessman::PAWN, Color::WHITE, 6, j);
}

ColeredChessman* Board::getChessman(int x, int y)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
	{
		return &checkerboard[x][y];
	}
}


Board Board::board;