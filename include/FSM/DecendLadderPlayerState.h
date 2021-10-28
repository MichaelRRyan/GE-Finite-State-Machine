#ifndef DECEND_LADDER_PLAYER_STATE_H
#define DECEND_LADDER_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include "FSM/PlayerState.h"
#include "FSM/ChangePlayerStateCommand.h"

class DecendLadderPlayerState : public PlayerState {
public:
	DecendLadderPlayerState(Player & t_player) : PlayerState(t_player) {}
	virtual Command * handleInput(ge::Events& input);
	virtual void update();
	virtual void enter();
	virtual void exit();
};

#endif
