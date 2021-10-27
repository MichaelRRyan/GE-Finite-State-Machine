#include "Events/Events.h"

#include "FSM/ClimbPausePlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/ClimbUpPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"


PlayerState* ClimbPausePlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::MOVE_DOWN_START_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::MOVE_UP_START_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> ClimbUpPlayerState");
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		//DEBUG_MSG("ClimbPausePlayerState -> LadderClimbedPlayerState");
		return new DecendLadderPlayerState();
	}
	return nullptr;
}
void ClimbPausePlayerState::update(Player& player) {}
void ClimbPausePlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering ClimbPausePlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 1608, 464, 282, 464 });
	
	player.getAnimatedSprite().setTime(0.05f);
}
void ClimbPausePlayerState::exit(Player& player) 
{
	//DEBUG_MSG("Exiting ClimbPausePlayerState");
}