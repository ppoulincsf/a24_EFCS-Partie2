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
  /// D�place le pacman selon une direction donn�e.
  /// </summary>
  /// <param name="direction">Direction dans laquelle on veut d�placer le pacman</param>
  /// <param name="grid">Grille de r�f�rence. Utilis�e pour ne pas que le pacman passe au travers des murs</param>
  virtual void move(Direction direction, const Grid& grid) override;

  void update(Grid& grid, const sf::Vector2i& pacmanPosition, bool isSuperPillActive);
  
  bool isWeak() const;
  void setIsWeak(bool isWeak);
  void setSpeedFactor(float factor);



private:
  /// <summary>
  /// Indique si le fant�me a �t� mang� par le pacman sans �tre
  /// retourn� dans sa cage pour se r�g�n�rer
  /// </summary>
  bool isGhostWeak;
  /// <summary>
  /// Identifiant du fant�me (entre 0 et 3 inclusivement) pour d�terminer
  /// la couleur par d�faut du fant�me dans la m�thode Draw.
  /// </summary>
  int ghostId = 0;

  float speedFactor;
  /// <summary>
  /// D�lai pour que le fant�me se mette en mouvement au d�but
  /// </summary>
  int activationDelay = 0;

  int getUpdateFrequency() const;
  
  static sf::Color ghostColors[];
  /// <summary>
  /// Compteur du nombre d'instances de fant�mes
  /// </summary>
  static int nbGhostCreated;

  // Propri�t�s SFML pour l'affichage
  sf::Texture ghostTextureNormal;
  sf::Texture ghostTextureScared;
  sf::Texture ghostTextureWeak;
  

};

