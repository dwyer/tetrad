#ifndef __TETRIS_H__
#define __TETRIS_H__
#include "tetrad.hpp"
#include "tilemap.hpp"

class Tetris {
  private:
    volatile int tick;
    BITMAP *bmp;
    Tetrad tetrad;
    Tilemap tilemap;
  
  public:
    Tetris(void);
    ~Tetris(void);
    void play(void);
};

#endif
