#pragma once
#include "Direction.h"
class Grid; 
#include "Character.h"

class Pacman : public Character
{
public:
  /// <summary>
  /// Constructeur
  /// </summary>
  /// <param name="row">Ligne de d�part du pacman</param>
  /// <param name="column">Colonne de d�part du pacman</param>
  Pacman(int row=0, int column=0);

  Pacman& operator=(const Pacman& other);
  /// <summary>
  /// D�place le pacman selon une direction donn�e.
  /// </summary>
  /// <param name="direction">Direction dans laquelle on veut d�placer le pacman</param>
  /// <param name="grid">Grille de r�f�rence. Utilis�e pour ne pas que le pacman passe au travers des murs</param>
  virtual void move(Direction direction, const  Grid& grid) override;

private:

  /// <summary>
  /// Angle du pacman. Pour l'affichage seulement;
  /// </summary>
  float angle = 0.0f;
};

