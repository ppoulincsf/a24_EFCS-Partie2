#pragma once
#include "PacmanElement.h"
#include "game.h"
class Grid
{
private:
  /// <summary>
  /// Grille logique du jeu
  /// </summary>  
  PacmanElement elements[Game::DEFAULT_GAME_WIDTH*Game::DEFAULT_GAME_HEIGHT];

  /// <summary>
  /// Position de la cage des fant�mes
  /// </summary>
  sf::Vector2i ghostCagePosition;

  /// <summary>
  /// Position originale du pacman
  /// </summary>
  sf::Vector2i pacmanOriginalPosition;

public:
  /// <summary>
  /// Constructeur
  /// </summary>
  Grid();
  
  /// <summary>
  /// Accesseur du num�ro de la ligne o� se trouve la cage � fant�mes
  /// </summary>
  int getGhostCagePositionRow() const;

  /// <summary>
  /// Accesseur du num�ro de la colonne o� se trouve la cage � fant�mes
  /// </summary>
  int getGhostCagePositionColumn() const;

  /// <summary>
  /// Accesseur du num�ro de la ligne o� se trouve le pacman au d�but
  /// </summary>
  int getPacmanOriginalPositionRow() const;

  /// <summary>
  /// Accesseur du num�ro de la colonne o� se trouve le pacman au d�but
  /// </summary>
  int getPacmanOriginalPositionColumn() const;

  /// <summary>
  /// Accesseur de la hauteur
  /// </summary>
  int getHeight() const;

  /// <summary>
  /// Accesseur de la largeur
  /// </summary>
  int getWidth() const;
  
  /// <summary>
  /// Charge un niveau � partir d'une chaine de caract�res en m�moire.
  /// Voir l'�nonc� du travail pour le format de la cha�ne.
  /// </summary>
  /// <param name="content"> Le contenu du niveau en m�moire</param>
  /// <returns>true si le chargement est correct, false sinon</returns>
  bool loadFromMemory(const std::string& content);

  /// <summary>
  /// Retourne l'�l�ment � la position sp�cifi�e
  /// </summary>
  /// <param name="row">La ligne</param>
  /// <param name="column">La colonne</param>
  /// <returns>L'�l�ment � la position sp�cifi�e</returns>
  PacmanElement getGridElementAt(int row, int column) const;

  /// <summary>
  /// Modifie le contenu du tableau � la position sp�cifi�e
  /// </summary>
  /// <param name="row">La ligne</param>
  /// <param name="column">La colonne</param>
  /// <param name="element">Le nouvel �l�ment � sp�cifier</param>
  void setGridElementAt(int row, int column, PacmanElement element);
  
private:
  Grid(const Grid& other);
  Grid& operator=(const Grid& other);
};

