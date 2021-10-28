#include "Events/Events.h"

#include "FSM/RevivedPlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"

Command * RevivedPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::DIED_EVENT)
	{
		//DEBUG_MSG("RevivedPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	return nullptr;
}
void RevivedPlayerState::update() {
	// Switch from RevivedPlayerState to IdlePlayerState
	//DEBUG_MSG("RevivedPlayerState -> IdlePlayerState");
	if (m_stopwatch.getSeconds() > 0.5f) {
		ChangePlayerStateCommand command(m_player, new IdlePlayerState(m_player));
		command.execute();
	}
}
void RevivedPlayerState::enter()
{
	//DEBUG_MSG("Entering RevivedPlayerState");
	
	// Starts the clock straight away.
	this->m_stopwatch.start();

	// Clear existing frames
	m_player.getAnimatedSprite().clearFrames();

	// Set animation control members
	m_player.getAnimatedSprite().setPlayed(false);
	m_player.getAnimatedSprite().setLooped(false);

	// Add animation frames
	m_player.getAnimatedSprite().addFrame({ 2454, 1494, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 3418, 996, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2936, 996, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2454, 996, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 3418, 498, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2936, 498, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2454, 498, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 3418, 0, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2936, 0, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2454, 0, 482, 498 });
	
	// Set the animation time
	m_player.getAnimatedSprite().setTime(0.03f);
}
void RevivedPlayerState::exit()
{
	//DEBUG_MSG("Exiting RevivedPlayerState");
	m_player.getAnimatedSprite().setPlayed(false);
	m_player.getAnimatedSprite().setLooped(true);
}