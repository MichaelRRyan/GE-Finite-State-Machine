#ifndef PLAYER_H
#define PLAYER_H

#include "FSM/PlayerState.h"
#include "Events/Events.h"
#include "Animation/AnimatedSprite.h"

class Player
{
private:

	PlayerState * m_state;
	AnimatedSprite * m_animatedSprite;

public:

	Player(AnimatedSprite * t_sprite);
	~Player();
	virtual void handleInput(ge::Events t_event);
	virtual void update();
	AnimatedSprite & getAnimatedSprite();
	AnimatedSprite & getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite * t_animatedSprite);
	PlayerState * getPlayerState();
	void setPlayerState(PlayerState * t_state);

    void render(SDL_Renderer * t_renderer);

};

#endif // !PLAYER_H

