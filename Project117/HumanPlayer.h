//HumanPlayer.h
#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__
#include "Player.h"
#include "GameManager.h"
class HumanPlayer : public Player {
public:
	HumanPlayer();
	void OnMove(/* parameters */) override;
	void OnPromote(Position p) override;
	GameManager GM;
	// your code¡K
};
#endif // !__HUMANPLAYER_H__