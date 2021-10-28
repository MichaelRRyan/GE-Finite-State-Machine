#include "Events/Events.h"

#include "FSM/DiedPlayerState.h"

#include "FSM/RevivedPlayerState.h"

Command * DiedPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::REVIVED_EVENT)
	{
		//DEBUG_MSG("DiedPlayerState -> RevivedPlayerState");
		return new ChangePlayerStateCommand(m_player, new RevivedPlayerState(m_player));
	}
	return nullptr;
}
void DiedPlayerState::update() {}
void DiedPlayerState::enter()
{
	//DEBUG_MSG("Entering DiedPlayerState");
	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().setPlayed(false);
	m_player.getAnimatedSprite().setLooped(false);

	m_player.getAnimatedSprite().addFrame({ 2454, 0, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2936, 0, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 3418, 0, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2454, 498, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2936, 498, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 3418, 498, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2454, 996, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2936, 996, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 3418, 996, 482, 498 });
	m_player.getAnimatedSprite().addFrame({ 2454, 1494, 482, 498 });

	m_player.getAnimatedSprite().setTime(0.03f);
}
void DiedPlayerState::exit()
{
	//DEBUG_MSG("Exiting DiedPlayerState");

	m_player.getAnimatedSprite().setPlayed(false);
	m_player.getAnimatedSprite().setLooped(true);
}