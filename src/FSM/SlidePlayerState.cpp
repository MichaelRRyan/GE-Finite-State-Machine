#include "Events/Events.h"

#include "FSM/SlidePlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"

Command * SlidePlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("SlidePlayerState -> RunRightPlayerState");
		return new ChangePlayerStateCommand(m_player, new RunRightPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("SlidePlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	return nullptr;
}
void SlidePlayerState::update() {
	// Switch from SlidePlayerState to IdlePlayerState
	// There is a fixed time at which the slide switched
	// back to IdlePlayerState....as the gameplay programmer
	// you may wish to stop the slide and have an appropriate
	// state and animation at the end of the slide
	// this was added so sliding does not go one indefinitely
	if (m_stopwatch.getSeconds() > 2.0f) {
		//DEBUG_MSG("SlidePlayerState -> IdlePlayerState");
		ChangePlayerStateCommand command(m_player, new IdlePlayerState(m_player));
		command.execute();
	}
}
void SlidePlayerState::enter()
{
	//DEBUG_MSG("Entering SlidePlayerState");

	// Starts the clock straight away.
	this->m_stopwatch.start();

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 0, 5388, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 373, 5388, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 746, 5388, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 0, 5739, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 373, 5739, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 746, 5739, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 0, 6090, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 373, 6090, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 746, 6090, 373, 351 });
	m_player.getAnimatedSprite().addFrame({ 0, 6441, 373, 351 });

	m_player.getAnimatedSpriteFrame().setTime(0.03f);
}
void SlidePlayerState::exit()
{
	//DEBUG_MSG("Exiting SlidePlayerState");
}