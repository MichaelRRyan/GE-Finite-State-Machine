#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Utils/Stopwatch.h"

class AnimatedSprite {
public:

	AnimatedSprite();
	AnimatedSprite(SDL_Texture * t_texture);
	AnimatedSprite(SDL_Texture * t_texture, SDL_Rect const & t_texRect);
	~AnimatedSprite();

	const util::Stopwatch & getStopwatch();
	const float getTime();
	const std::vector<SDL_Rect> & getFrames();
	void clearFrames();
	const SDL_Rect & getFrame(int t_frame);
	void addFrame(SDL_Rect const & t_frameRect);
	const int getCurrentFrame();
	void setLooped(bool t_loop);
	const bool getLooped();
	void setPlayed(bool t_played);
	const bool getPlayed();
	void setTime(float t_time);
	void update();

	void setPosition(float t_x, float t_y);
	
	SDL_Texture * getTexture();

	void render(SDL_Renderer * t_renderer);

private:

	util::Stopwatch m_stopwatch;
	float m_time;
	std::vector<SDL_Rect> m_frames;
	unsigned int m_currentFrame;
	bool m_loop;
	bool m_played;

	SDL_Texture * m_texture;
	float m_x;
	float m_y;

};

#endif // !ANIMATED_SPRITE_H
