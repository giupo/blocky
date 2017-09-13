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

# define MAX_BLOCKS 4 // Che tetris sarebbe? :D

class Piece {
  Block blocks[MAX_BLOCKS];
public:
  Piece() {}
  virtual ~Piece() {}
};

namespace Tetronimos {
  const int L[MAX_BLOCKS][MAX_BLOCKS] = {
    0,1,0,0,
    0,1,0,0,
    0,1,1,0,
    0,0,0,0
  };

  const int I[MAX_BLOCKS][MAX_BLOCKS] = {
    0,1,0,0,
    0,1,0,0,
    0,1,0,0,
    0,1,0,0
  };

  const int T[MAX_BLOCKS][MAX_BLOCKS] = {
    0,0,0,0,
    0,1,0,0,
    1,1,1,0,
    0,0,0,0
  };

  const int Z[MAX_BLOCKS][MAX_BLOCKS] = {
    0,0,0,0,
    1,1,0,0,
    0,1,1,0,
    0,0,0,0
  };
}

#endif
