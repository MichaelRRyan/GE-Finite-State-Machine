#include "Utils/Stopwatch.h"

Stopwatch::Stopwatch() :
    m_startTicks{ 0u },
    m_endTicks{ new Uint32{ 0u } }
{
}

void Stopwatch::start()
{
    m_startTicks = SDL_GetTicks();
    m_endTicks = nullptr;
}

void Stopwatch::stop()
{
    m_endTicks = new Uint32{ SDL_GetTicks() };
}

Uint32 Stopwatch::getTicks()
{
    if (m_endTime)
        return *m_endTicks - m_startTicks;
    else
        return SDL_GetTicks() - m_startTicks;
}

float Stopwatch::getSeconds()
{
    return static_cast<float>(getTicks()) / 1000.0f; 
}