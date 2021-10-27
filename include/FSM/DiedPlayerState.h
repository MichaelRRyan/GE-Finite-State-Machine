#ifndef DIED_PLAYER_STATE_H
#define DIED_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include <FSM/PlayerState.h>

class DiedPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(ge::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
};

#endif