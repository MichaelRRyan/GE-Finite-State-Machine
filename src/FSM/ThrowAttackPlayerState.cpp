#include "Events/Events.h"

#include "FSM/ThrowAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/DiedPlayerState.h"

Command * ThrowAttackPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new ChangePlayerStateCommand(m_player, new RunRightPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::THROW_STOP_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new ChangePlayerStateCommand(m_player, new IdlePlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("ThrowAttackPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	return nullptr;
}
void ThrowAttackPlayerState::update() {}
void ThrowAttackPlayerState::enter()
{
	//DEBUG_MSG("Entering AttackPlayerState");

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 6075, 0, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6452, 0, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6829, 0, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6075, 451, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6452, 451, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6829, 451, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6075, 902, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6452, 902, 377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6829, 902,377, 451 });
	m_player.getAnimatedSprite().addFrame({ 6075, 1353, 377, 451 });

	m_player.getAnimatedSprite().setTime(0.03f);
}
void ThrowAttackPlayerState::exit()
{
	//DEBUG_MSG("Exiting AttackPlayerState");
}