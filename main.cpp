#include "GameEngine.h"
#include "PlayState.h"
#include "IntroState.h"

int main ()
{
	GameEngine game( "Livade" );
	game.run( game.activate<IntroState>(true) );

	while( game.running() )
	{
		game.nextState();
		game.update();
		game.draw();
	}
    return 0;
}

