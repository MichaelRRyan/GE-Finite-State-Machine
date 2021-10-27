#ifndef IDLE_PLAYER_STATE_H
#define IDLE_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include <FSM/PlayerState.h>

class IdlePlayerState : public PlayerState{
public:
	virtual PlayerState* handleInput(ge::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
};
#endif