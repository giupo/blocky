#ifndef __BLOCK__
#define __BLOCK__

#include "SDL2/SDL.h"

class Block {
  SDL_Texture* texture;
public:
  enum class Color {
    nothing = 0,
    blue=1,
    darkgray,
    gray,
    green,
    lightblue,
    orange,
    pink,
    purple,
    red,
    red2,
    white
  };

  Block(): texture(NULL) {}
  virtual ~Block() {}
};

# define MAX_PIECES 4

class Piece {
  Block blocks[MAX_PIECES];
public:
  Piece() {}
  virtual ~Piece() {}
};

class Field {
  
  Block::Color container[30][10];
};

#endif
