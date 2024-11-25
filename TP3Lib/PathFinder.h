#pragma once
#include "Direction.h"
#include "game.h"
class Grid;
class PathFinder
{
public:
  static void initCosts(int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH], const Grid& aGrid, int fromX, int fromY);

  static Direction findShortestPath(const Grid& aGrid, int ghostPositionX, int ghostPositionY, int pacmanPositionX, int pacmanPositionY);

  static void computeCosts(const Grid& aMaze, int ghostPositionX, int ghostPositionY, int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH]);

  // Méthode récursive qui parcourt le tableau de coûts pour trouver le premier déplacement à faire.
  static Direction findFirstMoveToTarget(const int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH], int pacmanPositionX, int pacmanPositionY);
};

