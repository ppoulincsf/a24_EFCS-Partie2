#pragma once
#include "Character.h"
class Grid;
class Game;
#include "IntersectionType.h"
class PacmanBonus :
    public Character
{
 public:
   PacmanBonus(int x, int y);
   PacmanBonus(const PacmanBonus& src);

   void update(const Grid& grid);
   virtual void onPickedUp(Game& game) ;
   void respawn();
private:
  IntersectionType getIntersectionType(const Grid& grid, const sf::Vector2i& position, const sf::Vector2i& direction) const;
  
  sf::Vector2i direction;
  int nbArretEnT = 0;
  sf::Vector2i originalPosition;
};

