#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 980;
const int SCREEN_HEIGHT = 600;

class Game
{
public:

    Game();
    ~Game();
    void run();

private:

    void processEvents();
    void update();
    void render();

    void cleanUp();

    bool m_isRunning;

    //Render Window
	SDL_Window* m_window = NULL;
	
	SDL_Renderer* m_renderer;

};

#endif // !GAME_H