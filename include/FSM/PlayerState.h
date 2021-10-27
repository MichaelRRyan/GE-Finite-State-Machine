#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

#include "Events/Events.h"

class Player;

class PlayerState {
public:
	virtual ~PlayerState() {};
	virtual PlayerState * handleInput(ge::Events & t_event) = 0;
	virtual void update(Player & t_player) = 0;
	virtual void enter(Player & t_player) = 0;
	virtual void exit(Player & t_player) = 0;
};

#endif