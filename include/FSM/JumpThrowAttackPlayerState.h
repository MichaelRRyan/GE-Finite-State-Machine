#ifndef JUMP_THROW_ATTACK_PLAYER_STATE_H
#define JUMP_THROW_ATTACK_PLAYER_STATE_H

#include <GameObjects/Player.h>
#include <FSM/PlayerState.h>

class JumpThrowAttackPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(ge::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
};

#endif