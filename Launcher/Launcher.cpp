#include "pch.h"
#include "game.h"
int main()
{
  Game aGame("Pacman",
    Game::GAME_WIDTH,
    Game::GAME_HEIGHT);
  aGame.run();
}
