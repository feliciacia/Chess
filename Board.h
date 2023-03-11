#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include "Chessman.h"

using namespace std;

class Board {

public:
	Board();
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	static Board board;
	ColeredChessman checkerboard[8][8];
	void reset();
	ColeredChessman* getChessman(int x, int y);
};
#endif // !__BOARD_H_