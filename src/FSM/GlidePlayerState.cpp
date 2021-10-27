#include "Events/Events.h"

#include "FSM/GlidePlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"

PlayerState* GlidePlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::HIT_GROUND_EVENT)
	{
		//DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == ge::Events::Event::DIED_EVENT)
	{
		//DEBUG_MSG("GlidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void GlidePlayerState::update(Player& player) {
	//DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
	if (m_stopwatch.getSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void GlidePlayerState::enter(Player& player)
{
	//DEBUG_MSG("Entering RevivedPlayerState");

	// Starts the clock straight away.
	this->m_stopwatch.start();

	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame({ 0, 1992, 443, 454 });
	player.getAnimatedSprite().addFrame({ 443, 1992, 443, 454 });
	player.getAnimatedSprite().addFrame({ 886, 1992, 443, 454 });
	player.getAnimatedSprite().addFrame({ 0, 2446, 443, 454 });
	player.getAnimatedSprite().addFrame({ 443, 2446, 443, 454 });
	player.getAnimatedSprite().addFrame({ 886, 2446, 443, 454 });
	player.getAnimatedSprite().addFrame({ 0, 2900, 443, 454 });
	player.getAnimatedSprite().addFrame({ 443, 2900, 443, 454 });
	player.getAnimatedSprite().addFrame({ 886, 2900, 443, 454 });
	player.getAnimatedSprite().addFrame({ 0, 3354, 443, 454 });

	player.getAnimatedSprite().setTime(0.03f);
}
void GlidePlayerState::exit(Player& player)
{
	//DEBUG_MSG("Exiting RevivedPlayerState");
}