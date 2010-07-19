#include <allegro.h>
#include "tetrad.hpp"
#include "tilemap.hpp"


Tetrad::Tetrad(void) {
  init();
}


void Tetrad::init(void) {
  speed = 100;
  time = 0;
  type = rand() % TETRAD_NUM;
  x_pos = TILEMAP_W / 2 - 2;
  y_pos = 0;
  z_pos = 0;
}


void Tetrad::move(Tilemap &tilemap, int x, int y, int z) {
  if (tilemap.collision_check(type, x_pos+x, y_pos+y, z_pos+z)) {
    x_pos += x;
    y_pos += y;
    z_pos = (z_pos + z) % TETRAD_ROT;
  }
  else if (y > 0) {
    tilemap.put_tetrad(type, x_pos, y_pos, z_pos);
    init();
  }
}


void Tetrad::drop(Tilemap &tilemap) {
  while (tilemap.collision_check(type, x_pos, y_pos+1, z_pos)) {
    y_pos++;
  }
  move(tilemap, 0, 1, 0);
}


void Tetrad::update(Tilemap &tilemap) {
  if (time >= speed) {
    move(tilemap, 0, 1, 0);
    time -= speed;
  }
  time++;
}


void Tetrad::draw(BITMAP *bmp) {
  for (int i = 0; i != TETRAD_W; ++i) {
    for (int j = 0; j != TETRAD_H; ++j) {
      if (TETRAD[type][z_pos][i][j] != 0) {
        draw_tile(bmp, x_pos + i, y_pos + j, col[type]);
      }
    }
  }
}
