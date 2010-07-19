#include <allegro.h>
#include "image.hpp"


int Image::col[7];


void Image::init_color(void) {
  col[0] = makecol(0, 255, 255);  // cyan
  col[1] = makecol(0, 0, 255);    // blue
  col[2] = makecol(255, 127, 0);  // orange
  col[3] = makecol(255, 255, 0);  // yellow
  col[4] = makecol(0, 255, 0);    // green
  col[5] = makecol(127, 0, 127);  // purple
  col[6] = makecol(255, 0, 0);    // red
}


void Image::draw_tile(BITMAP *bmp, int x, int y, int col) {
  rectfill(bmp,
           x * TILE_SZ,
           y * TILE_SZ,
           (x + 1) * TILE_SZ - 1,
           (y + 1) * TILE_SZ - 1,
           col);
}
