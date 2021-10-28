#include "Events/Events.h"

#include "FSM/GlidePlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"

Command * GlidePlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::HIT_GROUND_EVENT)
	{
		//DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
		return new ChangePlayerStateCommand(m_player, new IdlePlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT)
	{
		//DEBUG_MSG("GlidePlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	return nullptr;
}
void GlidePlayerState::update() {
	//DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
	if (m_stopwatch.getSeconds() > 1.2f) {
		ChangePlayerStateCommand command(m_player, new IdlePlayerState(m_player));
		command.execute();
	}
}
void GlidePlayerState::enter()
{
	//DEBUG_MSG("Entering RevivedPlayerState");
	
	// Starts the clock straight away.
	this->m_stopwatch.start();

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 0, 1992, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 443, 1992, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 886, 1992, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 0, 2446, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 443, 2446, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 886, 2446, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 0, 2900, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 443, 2900, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 886, 2900, 443, 454 });
	m_player.getAnimatedSprite().addFrame({ 0, 3354, 443, 454 });

	m_player.getAnimatedSprite().setTime(0.03f);
}
void GlidePlayerState::exit()
{
	//DEBUG_MSG("Exiting RevivedPlayerState");
}