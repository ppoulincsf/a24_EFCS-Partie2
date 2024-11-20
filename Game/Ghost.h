#pragma once
#include "Direction.h"
class Grid;
#include "Character.h"
class Ghost : public Character
{
public:

  Ghost(int row=0, int column=0);
  Ghost& operator=(const Ghost& other);

  /// <summary>
  /// Déplace le pacman selon une direction donnée.
  /// </summary>
  /// <param name="direction">Direction dans laquelle on veut déplacer le pacman</param>
  /// <param name="grid">Grille de référence. Utilisée pour ne pas que le pacman passe au travers des murs</param>
  virtual void move(Direction direction, const Grid& grid) override;

  void update(Grid& grid, const sf::Vector2i& pacmanPosition, bool isSuperPillActive);
  
  bool isWeak() const;
  void setIsWeak(bool isWeak);
  void setSpeedFactor(float factor);



private:
  /// <summary>
  /// Indique si le fantôme a été mangé par le pacman sans être
  /// retourné dans sa cage pour se régénérer
  /// </summary>
  bool isGhostWeak;
  /// <summary>
  /// Identifiant du fantôme (entre 0 et 3 inclusivement) pour déterminer
  /// la couleur par défaut du fantôme dans la méthode Draw.
  /// </summary>
  int ghostId = 0;

  float speedFactor;
  /// <summary>
  /// Délai pour que le fantôme se mette en mouvement au début
  /// </summary>
  int activationDelay = 0;

  int getUpdateFrequency() const;
  
  static sf::Color ghostColors[];
  /// <summary>
  /// Compteur du nombre d'instances de fantômes
  /// </summary>
  static int nbGhostCreated;

  // Propriétés SFML pour l'affichage
  sf::Texture ghostTextureNormal;
  sf::Texture ghostTextureScared;
  sf::Texture ghostTextureWeak;
  

};

