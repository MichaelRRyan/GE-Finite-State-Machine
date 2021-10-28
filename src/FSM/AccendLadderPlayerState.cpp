#include "Events/Events.h"

#include "FSM/AccendLadderPlayerState.h"

#include "FSM/ClimbUpPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"

Command * AccendLadderPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_UP_START_EVENT)
	{
		//DEBUG_MSG("AccendLadderPlayerState -> ClimbUpPlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbUpPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("AccendLadderPlayerState -> RunRightPlayerState");
		return new ChangePlayerStateCommand(m_player, new RunRightPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("AccendLadderPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	
	return nullptr;
}
void AccendLadderPlayerState::update() {}
void AccendLadderPlayerState::enter()
{
	//DEBUG_MSG("Entering AccendLadderPlayerState");

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });

	m_player.getAnimatedSprite().setTime(0.05f);
}
void AccendLadderPlayerState::exit()
{
	//DEBUG_MSG("Exiting AccendLadderPlayerState");
}