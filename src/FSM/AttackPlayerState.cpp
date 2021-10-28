#include "Events/Events.h"

#include "FSM/AttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/DiedPlayerState.h"

Command * AttackPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new ChangePlayerStateCommand(m_player, new RunRightPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::ATTACK_STOP_EVENT)
	{
		//DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new ChangePlayerStateCommand(m_player, new IdlePlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("AttackPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}

	return nullptr;
}
void AttackPlayerState::update() {}
void AttackPlayerState::enter()
{
	//DEBUG_MSG("Entering AttackPlayerState");

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 0, 0, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 536, 0, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 1072, 0, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 0, 495, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 536, 495, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 1072, 495, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 0, 990, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 536, 990, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 1072, 990, 536, 495 });
	m_player.getAnimatedSprite().addFrame({ 0, 1485, 536, 495 });

	m_player.getAnimatedSprite().setTime(0.03f);
}
void AttackPlayerState::exit()
{
	//DEBUG_MSG("Exiting AttackPlayerState");
}