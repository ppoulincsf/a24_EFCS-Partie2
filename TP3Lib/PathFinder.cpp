#include "pch.h"
#include "PathFinder.h"
#include "Game.h"
#include "Grid.h"
void PathFinder::initCosts(int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH], const Grid &aGrid, int ghostPositionX, int ghostPositionY)
{
  // Initialisation du tableau de co�ts

  for (int row = 0; row < aGrid.getHeight(); row++)
  {
    for (int col = 0; col < aGrid.getWidth(); col++)
    {
      costs[row][col] = INT32_MAX;
    }
  }
  costs[ghostPositionY][ghostPositionX] = 0;
}

Direction PathFinder::findShortestPath(const Grid &aGrid, int ghostPositionX, int ghostPositionY, int pacmanPositionX, int pacmanPositionY)
{
  // Condition de base.  Si l'on est rendu, on retourne imm�diatement
  if (ghostPositionX == pacmanPositionX && ghostPositionY == pacmanPositionY)
    return Direction::None;

  // Si aucun chemin entre origine et destination
  if (aGrid.getGridElementAt(ghostPositionY, ghostPositionX) == PacmanElement::Wall || aGrid.getGridElementAt(pacmanPositionY, pacmanPositionX) == PacmanElement::Wall)
    return Direction::Undefined;

  // Initialisation du tableau de co�ts
  int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH];
  initCosts(costs, aGrid, ghostPositionX, ghostPositionY);

  // Calculer tous les co�ts entre le d�but et la fin de mani�re r�cursive
  computeCosts(aGrid, ghostPositionX, ghostPositionY, costs);

  Direction retval = Direction::Undefined;
  // Si un chemin existe...
  if (costs[pacmanPositionY][pacmanPositionX] < INT32_MAX)
  {
    // ... retrouver le premier d�placement � faire en partant de la position du pacman
    // jusqu'au fantôme
    // On cherche le déplacement du FANTOME
    retval = findFirstMoveToTarget(costs, pacmanPositionX, pacmanPositionY);
  }

  return retval;
}

void PathFinder::computeCosts(const Grid &aGrid, int col, int row, int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH])
{
  // A compléter pour le mandat 1
}

// M�thode r�cursive qui parcourt le tableau de co�ts pour trouver le premier d�placement � faire.
Direction PathFinder::findFirstMoveToTarget(int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH], int targetX, int targetY)
{
  // A compléter pour le mandat 2
  return Direction::Undefined;
}
