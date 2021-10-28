#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

#include "Events/Events.h"
#include "FSM/Command.h"

class Player;

class PlayerState {
public:

	PlayerState(Player & t_player) : m_player{ t_player } {}
	virtual ~PlayerState() {};
	virtual Command * handleInput(ge::Events & t_event) = 0;
	virtual void update() = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;

protected:

	Player & m_player;

};

#endif