#ifndef GLIDE_PLAYER_STATE_H
#define GLIDE_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include <FSM/PlayerState.h>
#include "Utils/Stopwatch.h"

class GlidePlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(ge::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	util::Stopwatch m_stopwatch;
};

#endif