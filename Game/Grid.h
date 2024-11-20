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
  /// Position de la cage des fantômes
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
  /// Accesseur du numéro de la ligne où se trouve la cage à fantômes
  /// </summary>
  int getGhostCagePositionRow() const;

  /// <summary>
  /// Accesseur du numéro de la colonne où se trouve la cage à fantômes
  /// </summary>
  int getGhostCagePositionColumn() const;

  /// <summary>
  /// Accesseur du numéro de la ligne où se trouve le pacman au début
  /// </summary>
  int getPacmanOriginalPositionRow() const;

  /// <summary>
  /// Accesseur du numéro de la colonne où se trouve le pacman au début
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
  /// Charge un niveau à partir d'une chaine de caractères en mémoire.
  /// Voir l'énoncé du travail pour le format de la chaîne.
  /// </summary>
  /// <param name="content"> Le contenu du niveau en mémoire</param>
  /// <returns>true si le chargement est correct, false sinon</returns>
  bool loadFromMemory(const std::string& content);

  /// <summary>
  /// Retourne l'élément à la position spécifiée
  /// </summary>
  /// <param name="row">La ligne</param>
  /// <param name="column">La colonne</param>
  /// <returns>L'élément à la position spécifiée</returns>
  PacmanElement getGridElementAt(int row, int column) const;

  /// <summary>
  /// Modifie le contenu du tableau à la position spécifiée
  /// </summary>
  /// <param name="row">La ligne</param>
  /// <param name="column">La colonne</param>
  /// <param name="element">Le nouvel élément à spécifier</param>
  void setGridElementAt(int row, int column, PacmanElement element);
  
private:
  Grid(const Grid& other);
  Grid& operator=(const Grid& other);
};

