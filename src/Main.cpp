#include <iostream>
#include "Game.h"

/*
    Adding the arg params but they aren't
    really necessary right now (or maybe ever)
*/
int main(int argc, char *argv[])
{
    Game game;
    game.Initialize();
    game.Run();
    game.Destroy();

    return 0;
}
