#ifndef RUN_RIGHT_PLAYER_STATE_H
#define RUN_RIGHT_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include "FSM/PlayerState.h"
#include "FSM/ChangePlayerStateCommand.h"

class RunRightPlayerState : public PlayerState {
public:
	RunRightPlayerState(Player & t_player) : PlayerState(t_player) {}
	virtual Command * handleInput(ge::Events& input);
	virtual void update();
	virtual void enter();
	virtual void exit();
};

#endif
