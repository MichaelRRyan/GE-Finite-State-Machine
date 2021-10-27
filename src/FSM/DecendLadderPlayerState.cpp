#include "Events/Events.h"

#include "FSM/DecendLadderPlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* DecendLadderPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_DOWN_START_EVENT)
	{
		//DEBUG_MSG("DecendLadderPlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::RUN_RIGHT_START_EVENT)
	{
		//DEBUG_MSG("DecendLadderPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("DecendLadderPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void DecendLadderPlayerState::update(Player& player) {}
void DecendLadderPlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering DecendLadderPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });

	player.getAnimatedSprite().setTime(0.05f);
}
void DecendLadderPlayerState::exit(Player& player)
{
	//DEBUG_MSG("Exiting DecendLadderPlayerState");
}