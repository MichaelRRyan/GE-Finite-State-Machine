#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() : 
	m_currentFrame(0),
	m_time(seconds(0.5f)),
	m_loop(true),
	m_played(false)
{
}

AnimatedSprite::AnimatedSprite(SDL_Texture const * t_texture) : 
	AnimatedSprite()
{
	m_texture = t_texture;
}

AnimatedSprite::AnimatedSprite(SDL_Texture const * t_texture, SDL_Rect const * t_texRect) : 
	AnimatedSprite(t_texture)
{
	m_frames.push_back(t_texRect);
}

AnimatedSprite::~AnimatedSprite()
{
}

const sf::Stopwatch & AnimatedSprite::getStopwatch()
{
	return m_clock;
}

float const AnimatedSprite::getTime()
{
	return m_time;
}

void AnimatedSprite::setTime(float t_time)
{
	m_time = t_time;
}

const std::vector<SDL_Rect> & AnimatedSprite::getFrames()
{
	return m_frames;
}

void AnimatedSprite::clearFrames()
{
	m_currentFrame = 0;
	m_played = false;
	if (!m_frames.empty())
	{
		m_frames.clear();
	}
}

SDL_Rect const * AnimatedSprite::getFrame(int t_frame)
{
	return m_frames[t_frame];
}

void AnimatedSprite::addFrame(SDL_Rect const * t_frameRect)
{
	m_frames.push_back(t_frameRect);
}

const int AnimatedSprite::getCurrentFrame()
{
	return m_currentFrame;
}

void AnimatedSprite::setLooped(bool t_loop)
{
	m_loop = loop;
}

const bool AnimatedSprite::getLooped()
{
	return m_loop;
}

void AnimatedSprite::setPlayed(bool t_played)
{
	m_played = played;
}

const bool AnimatedSprite::getPlayed()
{
	return m_played;
}

void AnimatedSprite::update()
{
	// If not looped only play once
	if (m_played == true && !m_loop)
	{
		m_currentFrame = m_frames.size() - 1;
	}
	else {
		if (m_stopwatch.getSeconds() > m_time) {
			if (m_frames.size() > m_currentFrame + 1)
			{
				m_currentFrame++;
			}
			else {
				m_currentFrame = 0;
				m_played = true;
			}
			m_stopwatch.start();
		}
	}
	
}

void setPosition(float t_x, float t_y)
{
	m_x = t_x;
	m_y = t_y;
}

SDL_Texture * getTexture()
{
	return m_texture;
}

void render(SDL_Renderer * t_renderer)
{
	SDL_Rect * frame = getFrame(getCurrentFrame());
	SDL_Rect destRect = { m_x, m_y, frame->w, frame->h };
	SDL_RenderCopy(t_renderer, m_texture, *frame, &destRect);
}