#include "GameObjects/Player.h"
#include <stdio.h>
//#include "IdlePlayerState.h"


Player::Player(AnimatedSprite const & t_sprite) : 
    m_animated_sprite(sprite)
{
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	//m_state = new IdlePlayerState();
	//m_state->enter(*this);
}

void Player::handleInput(ge::Events t_event) {
	PlayerState * state = m_state->handleInput(t_event);

	if (state != NULL) {
		m_state->exit(*this);
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}

void Player::update() {
	m_animated_sprite.update();
	m_state->update(*this);
}

AnimatedSprite& Player::getAnimatedSprite() {
	return m_animated_sprite;
}

AnimatedSprite& Player::getAnimatedSpriteFrame() {
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::setAnimatedSprite(AnimatedSprite& animated_sprite) {
	this->m_animated_sprite = animated_sprite;
}

PlayerState* Player::getPlayerState() { return this->m_state; }

void Player::setPlayerState(PlayerState* state) { this->m_state = state; }