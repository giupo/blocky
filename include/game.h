#ifndef __GAME__
#define __GAME__

#include "SDL2/SDL.h"

#include "LifeCycle.h"
#include "GameState.h"

class Game : public Loopable {
public:
  virtual void changeState(GameState* newState) =0;
  virtual void requestState(GameState* newState) =0;
protected:
  GameState* state;
  GameState* nextState;
};

class BlockyGame : public Game {
  friend class GameState;
private:
  SDL_Window* window;
  bool running;
  
public:
  BlockyGame(): window(NULL), running(false) {
    this->state = nullptr;
    this->nextState = nullptr;
  }
  virtual ~BlockyGame() {}

  // Loopable
  virtual void init();
  virtual void loop();
  virtual void shutdown();
  //Game
  virtual void changeState(GameState* state);
  virtual void requestState(GameState* newState);

  void setRunning(bool running);
};

#endif
