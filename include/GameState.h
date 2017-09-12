#ifndef __GAME_STATE__
#define __GAME_STATE__

#include "LifeCycle.h"
#include "SDL2/SDL.h"

#include "Block.h"

class BlockyGame;

class GameState : public Updatable {
public:
  virtual ~GameState() {}
  virtual void handleInput() = 0;
  virtual void init() = 0;
  virtual void update() = 0;
  virtual void shutdown() = 0;
};

class MainMenuState : public GameState {
  SDL_Texture* background_texture;
protected:
  friend class BlockyGame;
  BlockyGame* game;
public:
  MainMenuState(BlockyGame* game): background_texture(NULL) {
    this->game = game;
  }
  virtual ~MainMenuState () {}
  
  virtual void init();
  virtual void update();
  virtual void shutdown();

  virtual void handleInput();
};

class SinglePlayerState : public GameState {
  SDL_Texture* background;
  BlockyGame* game;
  unsigned int score;

  Piece* piece;
  Piece* nextPiece;
  
public:

  SinglePlayerState(BlockyGame *game): background(NULL) {
    this->game = game;
    this->piece = nullptr;
    this->nextPiece = nullptr;
  }
  
  // GameState
  virtual ~SinglePlayerState() {}
  virtual void handleInput();
  virtual void init();
  virtual void update();
  virtual void shutdown();
};

#endif
