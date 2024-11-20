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
  /// <param name="row">Ligne de départ du pacman</param>
  /// <param name="column">Colonne de départ du pacman</param>
  Pacman(int row=0, int column=0);

  Pacman& operator=(const Pacman& other);
  /// <summary>
  /// Déplace le pacman selon une direction donnée.
  /// </summary>
  /// <param name="direction">Direction dans laquelle on veut déplacer le pacman</param>
  /// <param name="grid">Grille de référence. Utilisée pour ne pas que le pacman passe au travers des murs</param>
  virtual void move(Direction direction, const  Grid& grid) override;

private:

  /// <summary>
  /// Angle du pacman. Pour l'affichage seulement;
  /// </summary>
  float angle = 0.0f;
};

