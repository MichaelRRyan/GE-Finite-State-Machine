#include "Events/Events.h"

#include "FSM/ClimbUpPlayerState.h"

#include "FSM/ClimbPausePlayerState.h"
#include "FSM/ClimbDownPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"


Command * ClimbUpPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_UP_STOP_EVENT)
	{
		//DEBUG_MSG("ClimbUpPlayerState -> ClimbPausePlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbPausePlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::MOVE_DOWN_START_EVENT)
	{
		//DEBUG_MSG("ClimbUpPlayerState -> ClimbDownPlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbDownPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		//DEBUG_MSG("ClimbUpPlayerState -> DecendLadderPlayerState");
		return new ChangePlayerStateCommand(m_player, new DecendLadderPlayerState(m_player));
	}
	
	return nullptr;
}
void ClimbUpPlayerState::update() {}
void ClimbUpPlayerState::enter() 
{
	//DEBUG_MSG("Entering ClimbUpPlayerState");
	
	// Climb Up Animated Sprite
	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 1608, 1392, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 2172, 928, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1890, 928, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1608, 928, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 2172, 464, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1890, 464, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 2172, 0, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1890, 0, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1608, 0, 282, 464 });
	
	m_player.getAnimatedSprite().setTime(0.05f);
}
void ClimbUpPlayerState::exit()
{
	//DEBUG_MSG("Exiting ClimbUpPlayerState");
}