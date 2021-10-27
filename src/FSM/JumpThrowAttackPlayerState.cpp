#include "Events/Events.h"

#include "FSM/JumpThrowAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/GlidePlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* JumpThrowAttackPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("JumpThrowAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::THROW_STOP_EVENT)
	{
		//DEBUG_MSG("JumpThrowAttackPlayerState -> GlidePlayerState");
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpThrowAttackPlayerState::update(Player& player) {}
void JumpThrowAttackPlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering JumpThrowAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 4596, 0, 360, 431 });
	player.getAnimatedSprite().addFrame({ 4956, 0, 360, 431 });
	player.getAnimatedSprite().addFrame({ 5316, 0, 360, 431 });
	player.getAnimatedSprite().addFrame({ 4596, 431, 360, 431 });
	player.getAnimatedSprite().addFrame({ 4956, 431, 360, 431 });
	player.getAnimatedSprite().addFrame({ 5316, 431, 360, 431 });
	player.getAnimatedSprite().addFrame({ 4596, 862, 360, 431 });
	player.getAnimatedSprite().addFrame({ 4956, 862, 360, 431 });
	player.getAnimatedSprite().addFrame({ 5316, 862, 360, 431 });
	player.getAnimatedSprite().addFrame({ 4596, 1293, 360, 431 });

	player.getAnimatedSprite().setTime(0.05f);
}
void JumpThrowAttackPlayerState::exit(Player& player)
{
	//DEBUG_MSG("Exiting JumpThrowAttackPlayerState");
}