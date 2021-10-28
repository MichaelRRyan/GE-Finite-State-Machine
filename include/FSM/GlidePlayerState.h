#ifndef GLIDE_PLAYER_STATE_H
#define GLIDE_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include "FSM/PlayerState.h"
#include "FSM/ChangePlayerStateCommand.h"
#include "Utils/Stopwatch.h"

class GlidePlayerState : public PlayerState {
public:
	GlidePlayerState(Player & t_player) : PlayerState(t_player) {}
	virtual Command * handleInput(ge::Events& input);
	virtual void update();
	virtual void enter();
	virtual void exit();
private:
	util::Stopwatch m_stopwatch;
};

#endif