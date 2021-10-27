#include "Events/Events.h"

#include "FSM/RunRightPlayerState.h"

#include "FSM/AttackPlayerState.h"
#include "FSM/ThrowAttackPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"
#include "FSM/JumpPlayerState.h"
#include "FSM/DiedPlayerState.h"
#include "FSM/SlidePlayerState.h"

PlayerState* RunRightPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::ATTACK_START_EVENT)
	{
		//DEBUG_MSG("RunRightPlayerState -> AttackPlayerState");
		return new AttackPlayerState();
	}
	if (input.getCurrent() == ge::Events::Event::THROW_START_EVENT)
	{
		//DEBUG_MSG("RunRightPlayerState -> ThrowAttackPlayerState");
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_WALL_EVENT || input.getCurrent() == ge::Events::Event::RUN_RIGHT_STOP_EVENT)
	{
		//DEBUG_MSG("RunRightPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		//DEBUG_MSG("RunRightPlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		//DEBUG_MSG("RunRightPlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::JUMP_UP_EVENT) {
		//DEBUG_MSG("IdlePlayerState -> JumpPlayerState");
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::SLIDE_EVENT) {
		//DEBUG_MSG("RunRightPlayerState -> SlidePlayerState");
		return new SlidePlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("RunRightPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void RunRightPlayerState::update(Player& player) {}
void RunRightPlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering RunRightPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 4986, 3556, 363, 458 });
	player.getAnimatedSprite().addFrame({ 5349, 3556, 363, 458 });
	player.getAnimatedSprite().addFrame({ 5712, 3556, 363, 458 });
	player.getAnimatedSprite().addFrame({ 4986, 4014, 363, 458 });
	player.getAnimatedSprite().addFrame({ 5349, 4014, 363, 458 });
	player.getAnimatedSprite().addFrame({ 5712, 4014, 363, 458 });
	player.getAnimatedSprite().addFrame({ 4986, 4472, 363, 458 });
	player.getAnimatedSprite().addFrame({ 5349, 4472, 363, 458 });
	player.getAnimatedSprite().addFrame({ 5712, 4472, 363, 458 });
	player.getAnimatedSprite().addFrame({ 4986, 4930, 363, 458 });

	player.getAnimatedSpriteFrame().setTime(0.05f);
}
void RunRightPlayerState::exit(Player& player) 
{
	//DEBUG_MSG("Exiting RunRightPlayerState");
}