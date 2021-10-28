#include "Events/Events.h"

#include "FSM/DecendLadderPlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"

Command * DecendLadderPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_DOWN_START_EVENT)
	{
		//DEBUG_MSG("DecendLadderPlayerState -> ClimbDownPlayerState");
		return new ChangePlayerStateCommand(m_player, new ClimbDownPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("DecendLadderPlayerState -> RunRightPlayerState");
		return new ChangePlayerStateCommand(m_player, new RunRightPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("DecendLadderPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	return nullptr;
}
void DecendLadderPlayerState::update() {}
void DecendLadderPlayerState::enter()
{
	//DEBUG_MSG("Entering DecendLadderPlayerState");

	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });

	m_player.getAnimatedSprite().setTime(0.05f);
}
void DecendLadderPlayerState::exit()
{
	//DEBUG_MSG("Exiting DecendLadderPlayerState");
}