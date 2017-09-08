#ifndef __GAME__
#define __GAME__

#include "SDL2/SDL.h"

#include "config4cpp/Configuration.h"

class Game {
public:
  virtual void init(config4cpp::Configuration* cfg) =0;
  virtual void loop() =0;
  virtual void shutdown() =0;
};

class BlockyGame : public Game {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* surface;
  SDL_Texture* texture;
  bool running;
public:
  BlockyGame(): window(NULL), renderer(NULL), surface(NULL), texture(NULL), running(false) {}
  virtual ~BlockyGame() {}
  virtual void init(config4cpp::Configuration* cfg);
  virtual void loop();
  virtual void shutdown();  
};

#endif
