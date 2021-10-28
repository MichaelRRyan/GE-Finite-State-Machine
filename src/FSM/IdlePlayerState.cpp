#include "Events/Events.h"

#include "FSM/IdlePlayerState.h"

#include "FSM/AttackPlayerState.h"
#include "FSM/ThrowAttackPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"
#include "FSM/JumpPlayerState.h"
#include "FSM/DiedPlayerState.h"


Command * IdlePlayerState::handleInput(ge::Events& input) {

	if (input.getCurrent() == ge::Events::Event::ATTACK_START_EVENT)
	{
		//DEBUG_MSG("IdlePlayerState -> AttackPlayerState");
		return new ChangePlayerStateCommand(m_player, new AttackPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::THROW_START_EVENT)
	{
		//DEBUG_MSG("IdlePlayerState -> ThrowAttackPlayerState");
		return new ChangePlayerStateCommand(m_player, new ThrowAttackPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT) {
		//DEBUG_MSG("IdlePlayerState -> RunRightPlayerState");
		return new ChangePlayerStateCommand(m_player, new RunRightPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_BOTTOM_EVENT) {
		//DEBUG_MSG("IdlePlayerState -> AccendLadderPlayerState");
		return new ChangePlayerStateCommand(m_player, new AccendLadderPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_TOP_EVENT) {
		//DEBUG_MSG("IdlePlayerState -> DecendLadderPlayerState");
		return new ChangePlayerStateCommand(m_player, new DecendLadderPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::JUMP_UP_EVENT) {
		//DEBUG_MSG("IdlePlayerState -> JumpPlayerState");
		return new ChangePlayerStateCommand(m_player, new JumpPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("IdlePlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	return nullptr;
}

void IdlePlayerState::update() {}

void IdlePlayerState::enter() 
{
	//DEBUG_MSG("Entering IdlePlayerState");
	
	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 3900, 0, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 4132, 0, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 4364, 0, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 3900, 439, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 4132, 439, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 4364, 439, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 3900, 878, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 4132, 878, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 4364, 878, 232, 439 });
	m_player.getAnimatedSprite().addFrame({ 3900, 1317, 232, 439 });
	
	m_player.getAnimatedSprite().setTime(0.05f);
}

void IdlePlayerState::exit()
{
	//DEBUG_MSG("Exiting IdlePlayerState");
}