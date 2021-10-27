#include "GameObjects/Player.h"
#include <stdio.h>
#include "FSM/IdlePlayerState.h"

Player::Player(AnimatedSprite * t_sprite) : 
    m_animatedSprite{ t_sprite }
{
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	m_state = new IdlePlayerState();
	m_state->enter(*this);
}

Player::~Player()
{
	delete m_animatedSprite;

	if (m_state) delete m_state;
}

void Player::handleInput(ge::Events t_event)
{
	if (m_state == nullptr) return;

	PlayerState * state = m_state->handleInput(t_event);

	if (state != NULL) {
		m_state->exit(*this);
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}

void Player::update() {
	m_animatedSprite->update();

	if (m_state)
		m_state->update(*this);
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

void Player::setPlayerState(PlayerState* state) { this->m_state = state; }

void Player::render(SDL_Renderer * t_renderer)
{
    m_animatedSprite->render(t_renderer);
}