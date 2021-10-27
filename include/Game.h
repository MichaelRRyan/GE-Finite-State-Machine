#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <vector>
#include "GameObjects/Player.h"
#include "Utils/Utility.h"
#include "Utils/Defines.h"

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

    Player * m_player;
    SDL_Texture * m_playerTexture;

};

#endif // !GAME_H