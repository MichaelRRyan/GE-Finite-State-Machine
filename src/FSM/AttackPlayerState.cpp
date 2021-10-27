#include "Events/Events.h"

#include "FSM/AttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* AttackPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::ATTACK_STOP_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("AttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void AttackPlayerState::update(Player& player) {}
void AttackPlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering AttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 0, 0, 536, 495 });
	player.getAnimatedSprite().addFrame({ 536, 0, 536, 495 });
	player.getAnimatedSprite().addFrame({ 1072, 0, 536, 495 });
	player.getAnimatedSprite().addFrame({ 0, 495, 536, 495 });
	player.getAnimatedSprite().addFrame({ 536, 495, 536, 495 });
	player.getAnimatedSprite().addFrame({ 1072, 495, 536, 495 });
	player.getAnimatedSprite().addFrame({ 0, 990, 536, 495 });
	player.getAnimatedSprite().addFrame({ 536, 990, 536, 495 });
	player.getAnimatedSprite().addFrame({ 1072, 990, 536, 495 });
	player.getAnimatedSprite().addFrame({ 0, 1485, 536, 495 });

	player.getAnimatedSprite().setTime(0.03f);
}
void AttackPlayerState::exit(Player& player)
{
	//DEBUG_MSG("Exiting AttackPlayerState");
}