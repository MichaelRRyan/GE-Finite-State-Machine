#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <SDL_Timer.h>

namespace util
{
    class Stopwatch
    {
    public:

        Stopwatch();

        void start();
        void stop();

        Uint32 getTicks();
        float getSeconds();

    private:

        Uint32 m_startTicks;
        Uint32 * m_endTicks;

    };
}

#endif // !STOPWATCH_H