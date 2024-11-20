#pragma once

#include "Ghost.h"
#include "Pacman.h"
#include "EndGameResult.h"
#include "BonusType.h"

// PROF
#include <list>
// #include "DoubleLinkedList.h"
class PacmanBonus;
class Grid;
class Game
{
public:
  static const int TARGET_FPS;

  /// <summary>
  /// Nombre de cases en largeur dans le jeu du Pacman
  /// </summary>
  static const int DEFAULT_GAME_WIDTH = 21;

  /// <summary>
    /// Durée d'activation d'une superpastille (en secondes)
    /// </summary>
  static const int SUPERPILL_ACTIVATION_TIME = 5000;

  /// <summary>
  /// Nombre de cases en hauteur dans le jeu du Pacman
  /// </summary>
  static const int DEFAULT_GAME_HEIGHT = 22;

  /// <summary>
  /// Largeur de rendu d'un élément de jeu
  /// </summary>
  static const int DEFAULT_GAME_ELEMENT_HEIGHT;

  /// <summary>
  /// Hauteur de rendu d'un élément de jeu
  /// </summary>
  static const int DEFAULT_GAME_ELEMENT_WIDTH;
  /// <summary>
  /// Largeur du jeu en pixels
  /// </summary>
  static const int GAME_WIDTH;

  /// <summary>
  /// Hauteur du jeu en pixels
  /// </summary>
  static const int GAME_HEIGHT;
public:

  Game(std::string windowName, unsigned int width, unsigned int height);
  ~Game();
  void run();

  /// <summary>
  /// Met à jour le jeu
  /// </summary>
  /// <returns>true si le jeu doit se terminer (partie perdue), false sinon</returns>
  EndGameResult update(sf::Keyboard::Key key);

  /// <summary>
  /// Dessine le jeu à l'écran
  /// </summary>
  /// <param name="window">Le contexte de rendu</param>
  void draw(sf::RenderWindow& window) const;

  /// <summary>
  /// Gère les entrées du joueur au clavier.
  /// </summary>
  /// <param name="keyPressed">La touche enfoncée par le joueur</param>
  void handleInput(sf::Keyboard::Key keyPressed);


  void addBonus(BonusType bonusType);
private:
  static const int NB_GHOSTS = 4;
  static const int BONUS_ZONE;
  Pacman pacman;

  /// <summary>
  /// Les 4 fantômes du jeu
  /// </summary>
  Ghost ghosts[NB_GHOSTS];
  sf::RenderWindow window;
  void drawBonuses(sf::RenderWindow& window) const;
  void handleEvents();
  bool init();
  bool isSuperPillActive() const;
  int countNbPillsRemaining() const;
  void useBonus(int bonus);
  /// <summary>
  /// La largeur du jeu en pixels
  /// </summary>
  int gameWidth;

  /// <summary>
  /// La hauteur du jeu en pixels
  /// </summary>
  int gameHeight;

  std::string gameName;

  Grid* grid;
  sf::Music beginningMusic;
  sf::Music deathMusic;
  sf::Music chompMusic;
  sf::Music pacmanEatsGhostMusic;
  const float SMALL_PILL_RADIUS = DEFAULT_GAME_ELEMENT_HEIGHT / 8.0f;
  const float SUPER_PILL_RADIUS = 2 * SMALL_PILL_RADIUS;
  
  int superPillsActivationTime;
  // Propriétés SFML pour l'affichage du labyrinthe
  sf::Texture wallTexture;
  mutable sf::Sprite wallSprite;
  sf::Keyboard::Key lastKeyPressed;
  float superPillsSizeFactor = 1.0f;
  float superPillsSizeFactorIncrement = -0.01f;

  PacmanBonus *bonus;
  // PROF  
  //DoubleLinkedList<BonusType> bonusList;
  std::list<BonusType> bonusList;
};

