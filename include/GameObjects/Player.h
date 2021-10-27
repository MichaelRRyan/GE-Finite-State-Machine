#ifndef PLAYER_H
#define PLAYER_H

#include "FSM/PlayerState.h"
#include "Events/Events.h"
#include "Animation/AnimatedSprite.h"

class Player
{
private:

	PlayerState * m_state;
	AnimatedSprite m_animated_sprite;

public:
	Player(AnimatedSprite const &);
	virtual void handleInput(ge::Events t_event);
	virtual void update();
	AnimatedSprite & getAnimatedSprite();
	AnimatedSprite & getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite & t_animatedSprite);
	PlayerState * getPlayerState();
	void setPlayerState(PlayerState * t_state);
};

#endif // !PLAYER_H

