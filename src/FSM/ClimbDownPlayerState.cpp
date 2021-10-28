#include "Events/Events.h"

#include "FSM/ClimbDownPlayerState.h"

#include "FSM/ClimbPausePlayerState.h"
#include "FSM/AccendLadderPlayerState.h"


Command * ClimbDownPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_DOWN_STOP_EVENT)
	{
		//DEBUG_MSG("ClimbDownPlayerState -> ClimbPausePlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbPausePlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		//DEBUG_MSG("ClimbDownPlayerState -> AccendLadderPlayerState");
		return new ChangePlayerStateCommand(m_player, new AccendLadderPlayerState(m_player));
	}
	
	return nullptr;
}
void ClimbDownPlayerState::update() {}
void ClimbDownPlayerState::enter()
{
	//DEBUG_MSG("Entering ClimbDownPlayerState");

	// Climb Down Animated Sprite
	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 1608, 0, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1890, 0, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 2172, 0, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1890, 464, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 2172, 464, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1608, 928, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1890, 928, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 2172, 928, 282, 464 });
	m_player.getAnimatedSprite().addFrame({ 1608, 1392, 282, 464 });

	m_player.getAnimatedSprite().setTime(0.05f);

}
void ClimbDownPlayerState::exit() 
{
	//DEBUG_MSG("Exiting ClimbDownPlayerState");
}