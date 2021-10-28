#include "Events/Events.h"

#include "FSM/JumpAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/GlidePlayerState.h"
#include "FSM/DiedPlayerState.h"

Command * JumpAttackPlayerState::handleInput(ge::Events& input)
{
	if (input.getCurrent() == ge::Events::Event::DIED_EVENT) {
		//DEBUG_MSG("JumpAttackPlayerState -> DiedPlayerState");
		return new ChangePlayerStateCommand(m_player, new DiedPlayerState(m_player));
	}
	else if (input.getCurrent() == ge::Events::Event::ATTACK_STOP_EVENT)
	{
		//DEBUG_MSG("JumpAttackPlayerState -> GlidePlayerState");
		return new ChangePlayerStateCommand(m_player, new GlidePlayerState(m_player));
	}
	return nullptr;
}
void JumpAttackPlayerState::update() {}
void JumpAttackPlayerState::enter()
{
	//DEBUG_MSG("Entering JumpAttackPlayerState");
	
	m_player.getAnimatedSprite().clearFrames();

	m_player.getAnimatedSprite().addFrame({ 1329, 1992, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 1851, 1992, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 2373, 1992, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 1329, 2514, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 1851, 2514, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 2373, 2514, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 1329, 3036, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 1851, 3036, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 2373, 3036, 504, 522 });
	m_player.getAnimatedSprite().addFrame({ 1329, 3558, 504, 522 });

	m_player.getAnimatedSprite().setTime(0.03f);
}
void JumpAttackPlayerState::exit()
{
	//DEBUG_MSG("Exiting JumpAttackPlayerState");
}