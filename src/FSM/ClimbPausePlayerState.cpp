#include "Events/Events.h"

#include "FSM/ClimbPausePlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/ClimbUpPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"


Command * ClimbPausePlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_DOWN_START_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> ClimbDownPlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbDownPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::MOVE_UP_START_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> ClimbUpPlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbUpPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> AccendLadderPlayerState");
		return new ChangePlayerStateCommand(m_player, new AccendLadderPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> LadderClimbedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DecendLadderPlayerState(m_player));
	}
	return nullptr;
}
void ClimbPausePlayerState::update() {}
void ClimbPausePlayerState::enter()
{
	//DEBUG_MSG("Entering ClimbPausePlayerState");

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });
	
	m_player.getAnimatedSprite().setTime(0.05f);
}
void ClimbPausePlayerState::exit() 
{
	//DEBUG_MSG("Exiting ClimbPausePlayerState");
}