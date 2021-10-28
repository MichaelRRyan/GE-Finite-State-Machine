#include "Game.h"

Game::Game() : 
    m_isRunning{ false }
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    
    //Create window
    m_window = SDL_CreateWindow("Render Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    if (m_window == nullptr)
        printf("Window Creation Error::SDL_Error: %s\n", SDL_GetError());
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_renderer == nullptr)
        printf("Renderer Creation Error::SDL_Error: %s\n", SDL_GetError());

    // Load a sprite to display.
    m_playerTexture = util::loadFromFile(util::PLAYER_SPRITES, m_renderer);
	if (m_playerTexture == nullptr)
	{
		m_playerTexture = util::loadFromFile(util::ERROR_SPRITES, m_renderer);

        if (m_playerTexture == nullptr)
            std::cout << "Error loading sprites." << std::endl;
	}

    // Setup Players Default Animated Sprite.
    m_player = new Player{ new AnimatedSprite{ m_playerTexture } };
}

Game::~Game()
{ 
    cleanUp(); 
}

void Game::run()
{
    m_isRunning = true;

    while (m_isRunning)
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    Uint8 const * keystate = SDL_GetKeyboardState(NULL);

    ge::Events event; // Finite state machine event.
    SDL_Event e; // Input event.
    while(SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            m_isRunning = false;
            break;
        }

        if (keystate)
        {
            switch (e.type)
            {
            case SDL_KEYDOWN:
                event.setCurrent(handleKeyDown(e, keystate));
                break;

            case SDL_KEYUP:
                event.setCurrent(handleKeyUp(e, keystate));
                break;
            }
        }
    }

    // Handle input to Player
    m_player->handleInput(event);
}

void Game::update()
{
    // Update the Player
	m_player->update();
}

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    // Draw the Players Current Animated Sprite
	m_player->render(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void Game::cleanUp()
{
    delete m_player;

    SDL_DestroyTexture(m_playerTexture);

    //Destroy window
	SDL_DestroyWindow( m_window );

	//Quit SDL subsystems
	SDL_Quit();
}

ge::Events::Event Game::handleKeyDown(SDL_Event const & t_triggerEvent, Uint8 const * t_keystates)
{
    // Died Event
    if (t_keystates[SDL_SCANCODE_D])
    {
        //DEBUG_MSG("ge::Events::Event::DIED_EVENT");
        return ge::Events::Event::DIED_EVENT;
    }
    // Revieved Event
    else if (t_keystates[SDL_SCANCODE_R])
    {
        //DEBUG_MSG("ge::Events::Event::REVIVED_EVENT");
        return ge::Events::Event::REVIVED_EVENT;
    }
    //Attack
    else if (t_keystates[SDL_SCANCODE_Z])
    {
        //DEBUG_MSG("ge::Events::Event::ATTACK_START_EVENT");
        return ge::Events::Event::ATTACK_START_EVENT;
    }
    // Throw Attack
    else if (t_keystates[SDL_SCANCODE_X])
    {
        //DEBUG_MSG("ge::Events::Event::THROW_START_EVENT");
        return ge::Events::Event::THROW_START_EVENT;
    }
    // Jump Run
    else if (t_keystates[SDL_SCANCODE_SPACE] && t_keystates[SDL_SCANCODE_RIGHT])
    {
        //DEBUG_MSG("ge::Events::Event::JUMP_UP_EVENT");
        return ge::Events::Event::JUMP_UP_EVENT;
    }
    // Running Slide
    else if (t_keystates[SDL_SCANCODE_DOWN] && t_keystates[SDL_SCANCODE_RIGHT])
    {
        //DEBUG_MSG("ge::Events::Event::SLIDE_EVENT");
        return ge::Events::Event::SLIDE_EVENT;
    }
    // Jump Event
    else if (t_keystates[SDL_SCANCODE_SPACE])
    {
        //DEBUG_MSG("ge::Events::Event::JUMP_UP_EVENT");
        return ge::Events::Event::JUMP_UP_EVENT;
    }
    // Running Slide
    else if (t_keystates[SDL_SCANCODE_DOWN] && t_keystates[SDL_SCANCODE_RIGHT])
    {
        //DEBUG_MSG("ge::Events::Event::SLIDE_EVENT");
        return ge::Events::Event::SLIDE_EVENT;
    }
    // Hit Ground Event
    else if (t_keystates[SDL_SCANCODE_H])
    {
        //DEBUG_MSG("ge::Events::Event::HIT_GROUND_EVENT");
        return ge::Events::Event::HIT_GROUND_EVENT;
    }
    // Run Right
    else if (t_keystates[SDL_SCANCODE_RIGHT])
    {
        //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
        return ge::Events::Event::RUN_RIGHT_START_EVENT;
    }
    // Climb Up
    else if (t_keystates[SDL_SCANCODE_UP])
    {
        //DEBUG_MSG("ge::Events::Event::MOVE_UP_START_EVENT");
        return ge::Events::Event::MOVE_UP_START_EVENT;
    }
    // Climb Down
    else if (t_keystates[SDL_SCANCODE_DOWN])
    {
        //DEBUG_MSG("ge::Events::Event::MOVE_DOWN_START_EVENT");
        return ge::Events::Event::MOVE_DOWN_START_EVENT;
    }
    // Hit Bottom of Ladder Event
    else if (t_keystates[SDL_SCANCODE_C])
    {
        //DEBUG_MSG("ge::Events::Event::HIT_LADDER_BOTTOM_EVENT");
        return ge::Events::Event::HIT_LADDER_BOTTOM_EVENT;
    }
    // Hit Top of Ladder Event
    else if (t_keystates[SDL_SCANCODE_T])
    {
        //DEBUG_MSG("ge::Events::Event::HIT_LADDER_TOP_EVENT");
        return ge::Events::Event::HIT_LADDER_TOP_EVENT;
    }

    return ge::Events::Event::NONE;
}

ge::Events::Event Game::handleKeyUp(SDL_Event const & t_triggerEvent, Uint8 const * t_keystates)
{
    // Run and Stop Attack
    if (t_triggerEvent.key.keysym.sym == SDLK_z && t_keystates[SDL_SCANCODE_RIGHT]) // If z is released and right is down.
    {
        //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
        return ge::Events::Event::RUN_RIGHT_START_EVENT;
    }
    // Stop Attack
    else if (t_triggerEvent.key.keysym.sym == SDLK_z)
    {
        //DEBUG_MSG("ge::Events::Event::ATTACK_STOP_EVENT");
        return ge::Events::Event::ATTACK_STOP_EVENT;
    }
    // Run and Stop Throw Attack
    else if (t_triggerEvent.key.keysym.sym == SDLK_x && t_keystates[SDL_SCANCODE_RIGHT]) // If x is released and right is down.
    {
        //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
        return ge::Events::Event::RUN_RIGHT_START_EVENT;
    }
    // Stop Throw Attack
    else if (t_triggerEvent.key.keysym.sym == SDLK_x)
    {
        //DEBUG_MSG("ge::Events::Event::THROW_STOP_EVENT");
        return ge::Events::Event::THROW_STOP_EVENT;
    }
    // Stop Running Right
    else if (t_triggerEvent.key.keysym.sym == SDLK_RIGHT)
    {
        //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_STOP_EVENT");
        return ge::Events::Event::RUN_RIGHT_STOP_EVENT;
    } 
    // Stop Slide
    else if (t_triggerEvent.key.keysym.sym == SDLK_DOWN && t_keystates[SDL_SCANCODE_RIGHT]) // If down released and right is down.
    {
        //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
        return ge::Events::Event::RUN_RIGHT_START_EVENT;
    }
    // Stop Moving Up
    else if (t_triggerEvent.key.keysym.sym == SDLK_UP)
    {
        //DEBUG_MSG("ge::Events::Event::MOVE_UP_STOP_EVENT");
        return ge::Events::Event::MOVE_UP_STOP_EVENT;
    }
    // Stop Moving Down
    else if (t_triggerEvent.key.keysym.sym == SDLK_DOWN)
    {
        //DEBUG_MSG("ge::Events::Event::MOVE_DOWN_STOP_EVENT");
        return ge::Events::Event::MOVE_DOWN_STOP_EVENT;
    }

    return ge::Events::Event::NONE;
}