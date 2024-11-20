#include "stdafx.h"
#include "CppUnitTest.h"
#include "PathFinder.h"
#include "levels.h"
#include "costs.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsPathFinder
{
  TEST_CLASS(PathFinderTests)
  {
  public:

    TEST_METHOD(VOTRE_NOM)
    {
      // TODO: Ici, votre code de test
      TEST_METHOD(computeCost_Levels1_CostsOKAtPacmanPosition)
      {
        // Arrange
        int costs[Game::DEFAULT_GAME_HEIGHT][Game::DEFAULT_GAME_WIDTH];
        Grid grid;
        grid.loadFromMemory(level1);
        PathFinder::initCosts(costs, grid, grid.getPacmanOriginalPositionColumn(), grid.getPacmanOriginalPositionRow());

        //Act
        PathFinder::computeCosts(grid, grid.getPacmanOriginalPositionColumn(), grid.getPacmanOriginalPositionRow(), costs);

        // Assert
        Assert::AreEqual(0, costs[grid.getPacmanOriginalPositionRow()][grid.getPacmanOriginalPositionColumn()]);

      }
      // Vous devez compléter ici les autres tests pour computeCosts







      TEST_METHOD(findFirstMoveToTarget_GhostLeftFromPacman)
      {
        // Arrange
        const Direction EXPECTED_DIRECTION = Direction::East;
        const int PACMAN_POSITION_COL = 6;
        const int PACMAN_POSITION_ROW = 13;

        //Act
        Direction direction = PathFinder::findFirstMoveToTarget(costs1, PACMAN_POSITION_COL, PACMAN_POSITION_ROW);

        // Assert
        Assert::IsTrue(EXPECTED_DIRECTION == direction);

      }
      // Vous devez compléter ici les autres tests pour findFirstMoveToTarget
    };
  }