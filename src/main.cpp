#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "Game.h"

int main( int argc, char* argv[] )
{
	// Handle arguments (Note C style)
	printf( "argc = %d\n", argc );
    for( int i = 0; i < argc; ++i ) {
        printf( "argv[ %d ] = %s\n", i, argv[ i ] );
    }

	Game game;
	game.run();

	return 0;
}
