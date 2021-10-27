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
    m_player->getAnimatedSprite().addFrame({ 3900, 0, 232, 439 });
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

    std::map<Uint32, std::vector<int>> inputs;

    SDL_Event e;
    while(SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            m_isRunning = false;
            break;
        }

        inputs[e.type].push_back(e.key.keysym.sym);
    }

    for (std::pair<Uint32 const, std::vector<int>> & input : inputs)
    {
        switch (input.first)
        {
        case SDL_KEYDOWN:
            
            // if (input.second == SDLK_d)
            // {

            // }
            break;
        case SDL_KEYUP:
            break;
        
        default:
            break;
        }
    }

    // // Handle input to Player
    // m_player->handleInput(event);

    // switch (event.type)
    // {
    // case sf::Event::Closed:
    //     // Close window : exit
    //     window.close();
    //     break;
    //     // Deal with KeyPressed
    // case sf::Event::KeyPressed:
    //     // Died Event
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    //         DEBUG_MSG("gpp::Events::Event::DIED_EVENT");
    //         input.setCurrent(gpp::Events::Event::DIED_EVENT);
    //     }
    //     // Revieved Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
    //         DEBUG_MSG("gpp::Events::Event::REVIVED_EVENT");
    //         input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
    //     }
    //     // Running attack
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
    //         ||
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
    //         )
    //     {
    //         DEBUG_MSG("gpp::Events::Event::ATTACK_START");
    //         input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
    //     }
    //     // Attack
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::ATTACK_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
    //     }
    //     // Throw attack
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
    //         ||
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::X)
    //         )
    //     {
    //         DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
    //     }
    //     // Throw Attack
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
    //     }
    //     // Run Right
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
    //     }
    //     // Climb Up
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::MOVE_UP_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
    //     }
    //     // Climb Down
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
    //     }
    //     // Hit Bottom of Ladder Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT");
    //         input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
    //     }
    //     // Hit Top of Ladder Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::HIT_LADDER_TOP_EVENT");
    //         input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
    //     }
    //     // Jump Run
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
    //         ||
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
    //         )
    //     {
    //         DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
    //         input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
    //     }
    //     // Jump Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
    //         input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
    //     }
    //     // Running Slide
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
    //         ||
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
    //         )
    //     {
    //         DEBUG_MSG("gpp::Events::Event::SLIDE_EVENT");
    //         input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
    //     }
    //     // Hit Ground Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
    //         input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
    //     }

    //     // Jump Attack Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
    //         input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
    //     }

    //     // Jump Throw Attack Event
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
    //         input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
    //     }
    //     break;

    //     // Deal with KeyReleased
    // case sf::Event::KeyReleased:
    //     // Run and Stop Attack
    //     if (event.key.code == sf::Keyboard::Z 
    //         && 
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
    //     }
    //     // Stop Attack
    //     else if(event.key.code == sf::Keyboard::Z)
    //     {
    //         DEBUG_MSG("gpp::Events::Event::ATTACK_STOP_EVENT");
    //         input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
    //     }
    //     // Run and Stop Throw Attack
    //     else if (event.key.code == sf::Keyboard::X
    //         &&
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
    //     }
    //     // Stop Throw Attack
    //     else if (event.key.code == sf::Keyboard::X)
    //     {
    //         DEBUG_MSG("gpp::Events::Event::THROW_STOP_EVENT");
    //         input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
    //     }
    //     // Stop Running Right
    //     else if (event.key.code == sf::Keyboard::Right)
    //     {
    //         DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_STOP_EVENT");
    //         input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
    //     }
    //     // Stop Slide
    //     else if (event.key.code == sf::Keyboard::Down 
    //         &&
    //         sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
    //         input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
    //     }
    //     // Stop Moving Up
    //     else if (event.key.code == sf::Keyboard::Up)
    //     {
    //         DEBUG_MSG("gpp::Events::Event::MOVE_UP_STOP_EVENT");
    //         input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
    //     }
    //     // Stop Moving Down
    //     else if (event.key.code == sf::Keyboard::Down)
    //     {
    //         DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_STOP_EVENT");
    //         input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
    //     }
    //     break;

    // default:
    //     DEBUG_MSG("gpp::Events::Event::NONE");
    //     input.setCurrent(gpp::Events::Event::NONE);
    //     break;
    // }
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
    //Destroy window
	SDL_DestroyWindow( m_window );

	//Quit SDL subsystems
	SDL_Quit();
}