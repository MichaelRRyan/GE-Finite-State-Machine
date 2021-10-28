#include "Events/Events.h"

#include "FSM/JumpPlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/JumpAttackPlayerState.h"
#include "FSM/JumpThrowAttackPlayerState.h"
#include "FSM/GlidePlayerState.h"

Command * JumpPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("JumpPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::ATTACK_START_EVENT)
	{
		//DEBUG_MSG("JumpPlayerState -> JumpAttackPlayerState");
		return new ChangePlayerStateCommand(m_player, new JumpAttackPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::THROW_START_EVENT)
	{
		//DEBUG_MSG("JumpPlayerState -> JumpThrowAttackPlayerState");
		return new ChangePlayerStateCommand(m_player, new JumpThrowAttackPlayerState(m_player));
	}
	return nullptr;
}
void JumpPlayerState::update() {
	//DEBUG_MSG("JumpPlayerState -> GlidePlayerState");
	if (m_stopwatch.getSeconds() > 1.2f) {
		ChangePlayerStateCommand command(m_player, new GlidePlayerState(m_player));
		command.execute();
	}
}
void JumpPlayerState::enter()
{
	//DEBUG_MSG("Entering JumpPlayerState");
	
	// Starts the clock straight away.
	this->m_stopwatch.start();

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().setPlayed(false);
	m_player.getAnimatedSprite().setLooped(false);

	m_player.getAnimatedSprite().addFrame({ 3900, 1756, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 4262, 1756, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 4624, 1756, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 3900, 2239, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 4262, 2239, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 4624, 2239, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 3900, 2722, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 4262, 2722, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 4624, 2722, 362, 483 });
	m_player.getAnimatedSprite().addFrame({ 3900, 3205, 362, 483 });

	m_player.getAnimatedSpriteFrame().setTime(0.03f);
}
void JumpPlayerState::exit()
{
	//DEBUG_MSG("Exiting JumpPlayerState");
	m_player.getAnimatedSprite().setPlayed(false);
	m_player.getAnimatedSprite().setLooped(true);
}