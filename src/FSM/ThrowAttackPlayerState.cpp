#include "Events/Events.h"

#include "FSM/ThrowAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* ThrowAttackPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::THROW_STOP_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("ThrowAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void ThrowAttackPlayerState::update(Player& player) {}
void ThrowAttackPlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering AttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 6075, 0, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6452, 0, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6829, 0, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6075, 451, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6452, 451, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6829, 451, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6075, 902, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6452, 902, 377, 451 });
	player.getAnimatedSprite().addFrame({ 6829, 902,377, 451 });
	player.getAnimatedSprite().addFrame({ 6075, 1353, 377, 451 });

	player.getAnimatedSprite().setTime(0.03f);
}
void ThrowAttackPlayerState::exit(Player& player)
{
	//DEBUG_MSG("Exiting AttackPlayerState");
}