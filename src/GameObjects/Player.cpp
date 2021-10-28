#include "GameObjects/Player.h"
#include <stdio.h>
#include "FSM/IdlePlayerState.h"

Player::Player(AnimatedSprite * t_sprite) : 
    m_animatedSprite{ t_sprite }
{
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	m_state = new IdlePlayerState(*this);
	m_state->enter();
}

Player::~Player()
{
	delete m_animatedSprite;

	if (m_state) delete m_state;
}

void Player::handleInput(ge::Events t_event)
{
	if (m_state == nullptr) return;

	Command * command = m_state->handleInput(t_event);

	if (command != nullptr) 
	{
		command->execute();
		delete command;
	}
}

void Player::update() {
	m_animatedSprite->update();

	if (m_state) m_state->update();
}

AnimatedSprite& Player::getAnimatedSprite() {
	return *m_animatedSprite;
}

AnimatedSprite& Player::getAnimatedSpriteFrame() {
	return *m_animatedSprite;
}

void Player::setAnimatedSprite(AnimatedSprite * animated_sprite) {
	this->m_animatedSprite = animated_sprite;
}

PlayerState* Player::getPlayerState() { return this->m_state; }

void Player::setPlayerState(PlayerState* state)
{ 
	if (m_state)
	{
		m_state->exit();
		delete m_state;
	}

	m_state = state;
	m_state->enter();
}

void Player::render(SDL_Renderer * t_renderer)
{
    m_animatedSprite->render(t_renderer);
}