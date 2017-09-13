#ifndef __TETRIS_GAME__
#define __TETRIS_GAME__

#include "Field.h"


class Piece {
  
};

class TetrisGame {
public:

  /* Life Cycle methods */

  TetrisGame() : TetrisGame(NUM_ROWS, NUM_COLS) {}
  TetrisGame(int x, int y);
  ~TetrisGame();
  
  /* @brief spawns the next piece */
  void spawnPiece();

  /**
   *  @brief steps the game, indipendently from game speed (influenced by many factors) 
   */
  void step();

  /* @brief checks if there are completes lines in the Field */
  void checkLines();

  /* @brief checks game ended conditions */
  bool isOver();
  
private:
  Field *field;
  
};

#endif
