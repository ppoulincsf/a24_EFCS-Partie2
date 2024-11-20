#pragma once
#include "Direction.h"
class Grid;
class Character
{
public:
  Character(std::string textureFile);
  Character(std::string textureFile, int x, int y);
  Character(const Character& other);
  virtual ~Character() = default;
  Character& operator=(const Character&);

  virtual void move(Direction direction, const  Grid& grid);
  void draw(sf::RenderWindow& window) const;

  int getColumn() const;

  /// <summary>
  /// Accesseur de la position en ligne
  /// </summary>
  int getRow() const;

  bool collidesWith(const Character& other) const;

protected:
  sf::Vector2i position;
  int updateCounter = 0;
  int updateFrequency;
  // Propriétés SFML pour l'affichage
  sf::Texture texture;
  sf::Sprite sprite;
  std::string textureFile;
  bool isVisible;
};

