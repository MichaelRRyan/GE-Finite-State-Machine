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
    ge::Events event;

    std::map<Uint32, std::set<int>> inputs;

    SDL_Event e;
    while(SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            m_isRunning = false;
            break;
        }

        inputs[e.type].insert(e.key.keysym.sym);
    }

    for (std::pair<Uint32 const, std::set<int>> & input : inputs)
    {
        switch (input.first)
        {
        case SDL_KEYDOWN:
            
            // Died Event
            if (input.second.count(SDLK_d) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::DIED_EVENT");
                event.setCurrent(ge::Events::Event::DIED_EVENT);
            }
            // Revieved Event
            else if (input.second.count(SDLK_r) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::REVIVED_EVENT");
                event.setCurrent(ge::Events::Event::REVIVED_EVENT);
            }
            // Running attack
            else if (input.second.count(SDLK_z) > 0 && input.second.count(SDLK_RIGHT) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::ATTACK_START");
                event.setCurrent(ge::Events::Event::ATTACK_START_EVENT);
            }
            //Attack
            else if (input.second.count(SDLK_z) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::ATTACK_START_EVENT");
                event.setCurrent(ge::Events::Event::ATTACK_START_EVENT);
            }
            // Throw attack
            else if (input.second.count(SDLK_x) > 0 && input.second.count(SDLK_RIGHT) > 0) 
            {
                //DEBUG_MSG("ge::Events::Event::THROW_START_EVENT");
                event.setCurrent(ge::Events::Event::THROW_START_EVENT);
            }
            // Throw Attack
            else if (input.second.count(SDLK_x) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::THROW_START_EVENT");
                event.setCurrent(ge::Events::Event::THROW_START_EVENT);
            }
            // Run Right
            else if (input.second.count(SDLK_RIGHT) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
                event.setCurrent(ge::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Climb Up
            else if (input.second.count(SDLK_UP) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::MOVE_UP_START_EVENT");
                event.setCurrent(ge::Events::Event::MOVE_UP_START_EVENT);
            }
            // Climb Down
            else if (input.second.count(SDLK_DOWN) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::MOVE_DOWN_START_EVENT");
                event.setCurrent(ge::Events::Event::MOVE_DOWN_START_EVENT);
            }
            // Hit Bottom of Ladder Event
            else if (input.second.count(SDLK_c) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::HIT_LADDER_BOTTOM_EVENT");
                event.setCurrent(ge::Events::Event::HIT_LADDER_BOTTOM_EVENT);
            }
            // Hit Top of Ladder Event
            else if (input.second.count(SDLK_t) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::HIT_LADDER_TOP_EVENT");
                event.setCurrent(ge::Events::Event::HIT_LADDER_TOP_EVENT);
            }
            // Jump Run
            if (input.second.count(SDLK_SPACE) > 0 && input.second.count(SDLK_RIGHT) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::JUMP_UP_EVENT");
                event.setCurrent(ge::Events::Event::JUMP_UP_EVENT);
            }
            // Jump Event
            else if (input.second.count(SDLK_SPACE) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::JUMP_UP_EVENT");
                event.setCurrent(ge::Events::Event::JUMP_UP_EVENT);
            }
            // Running Slide
            else if (input.second.count(SDLK_DOWN) > 0 && input.second.count(SDLK_RIGHT) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::SLIDE_EVENT");
                event.setCurrent(ge::Events::Event::SLIDE_EVENT);
            }
            // Hit Ground Event
            else if (input.second.count(SDLK_h) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::HIT_GROUND_EVENT");
                event.setCurrent(ge::Events::Event::HIT_GROUND_EVENT);
            }

            // Jump Attack Event
            else if (input.second.count(SDLK_h) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::HIT_GROUND_EVENT");
                event.setCurrent(ge::Events::Event::HIT_GROUND_EVENT);
            }

            // Jump Throw Attack Event
            else if (input.second.count(SDLK_h) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::HIT_GROUND_EVENT");
                event.setCurrent(ge::Events::Event::HIT_GROUND_EVENT);
            }

            break;
        case SDL_KEYUP:

            // Run and Stop Attack
            if (input.second.count(SDLK_z) > 0 && input.second.count(SDLK_RIGHT) > 0) // If z is released and right is down.
            {
                //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
                event.setCurrent(ge::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Stop Attack
            else if(input.second.count(SDLK_z) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::ATTACK_STOP_EVENT");
                event.setCurrent(ge::Events::Event::ATTACK_STOP_EVENT);
            }
            // Run and Stop Throw Attack
            else if (input.second.count(SDLK_z) > 0 && input.second.count(SDLK_RIGHT) > 0) // If x is released and right is down.
            {
                //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
                event.setCurrent(ge::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Stop Throw Attack
            else if (input.second.count(SDLK_x) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::THROW_STOP_EVENT");
                event.setCurrent(ge::Events::Event::THROW_STOP_EVENT);
            }
            // Stop Running Right
            else if (input.second.count(SDLK_RIGHT) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_STOP_EVENT");
                event.setCurrent(ge::Events::Event::RUN_RIGHT_STOP_EVENT);
            }
            // Stop Slide
            else if (input.second.count(SDLK_DOWN) > 0 && input.second.count(SDLK_RIGHT) > 0) // If down released and right is down.
            {
                //DEBUG_MSG("ge::Events::Event::RUN_RIGHT_START_EVENT");
                event.setCurrent(ge::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Stop Moving Up
            else if (input.second.count(SDLK_UP) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::MOVE_UP_STOP_EVENT");
                event.setCurrent(ge::Events::Event::MOVE_UP_STOP_EVENT);
            }
            // Stop Moving Down
            else if (input.second.count(SDLK_DOWN) > 0)
            {
                //DEBUG_MSG("ge::Events::Event::MOVE_DOWN_STOP_EVENT");
                event.setCurrent(ge::Events::Event::MOVE_DOWN_STOP_EVENT);
            }

            break;
        
        default:
            //DEBUG_MSG("ge::Events::Event::NONE");
            event.setCurrent(ge::Events::Event::NONE);
            break;
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