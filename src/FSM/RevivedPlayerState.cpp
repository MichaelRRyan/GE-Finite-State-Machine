#include "Events/Events.h"

#include "FSM/RevivedPlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"

PlayerState* RevivedPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::DIED_EVENT)
	{
		//DEBUG_MSG("RevivedPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void RevivedPlayerState::update(Player& player) {
	// Switch from RevivedPlayerState to IdlePlayerState
	//DEBUG_MSG("RevivedPlayerState -> IdlePlayerState");
	if (m_stopwatch.getSeconds() > 0.5f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void RevivedPlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering RevivedPlayerState");

	// Starts the clock straight away.
	this->m_stopwatch.start();

	// Clear existing frames
	player.getAnimatedSprite().clearFrames();

	// Set animation control members
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	// Add animation frames
	player.getAnimatedSprite().addFrame({ 2454, 1494, 482, 498 });
	player.getAnimatedSprite().addFrame({ 3418, 996, 482, 498 });
	player.getAnimatedSprite().addFrame({ 2936, 996, 482, 498 });
	player.getAnimatedSprite().addFrame({ 2454, 996, 482, 498 });
	player.getAnimatedSprite().addFrame({ 3418, 498, 482, 498 });
	player.getAnimatedSprite().addFrame({ 2936, 498, 482, 498 });
	player.getAnimatedSprite().addFrame({ 2454, 498, 482, 498 });
	player.getAnimatedSprite().addFrame({ 3418, 0, 482, 498 });
	player.getAnimatedSprite().addFrame({ 2936, 0, 482, 498 });
	player.getAnimatedSprite().addFrame({ 2454, 0, 482, 498 });
	
	// Set the animation time
	player.getAnimatedSprite().setTime(0.03f);
}
void RevivedPlayerState::exit(Player& player)
{
	//DEBUG_MSG("Exiting RevivedPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}