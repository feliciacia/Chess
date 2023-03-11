//Player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Position.h"
class Player {
public:
	Player();
	virtual void OnMove(/*ex. Board& const board, Position & outFromPos, Position& outToPos*/) = 0; // 選擇要從 fromPos 走到 toPos
	virtual void OnPromote(Position p) = 0; // 選擇升階類型
	virtual ~Player() = 0;
};
#endif // !__PLAYER_H__
