#ifndef ACCEND_LADDER_PLAYER_STATE_H
#define ACCEND_LADDER_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include <FSM/PlayerState.h>

class AccendLadderPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(ge::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
};

#endif