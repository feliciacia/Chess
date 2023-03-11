//Player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Position.h"
class Player {
public:
	Player();
	virtual void OnMove(/*ex. Board& const board, Position & outFromPos, Position& outToPos*/) = 0; // ��ܭn�q fromPos ���� toPos
	virtual void OnPromote(Position p) = 0; // ��ܤɶ�����
	virtual ~Player() = 0;
};
#endif // !__PLAYER_H__
