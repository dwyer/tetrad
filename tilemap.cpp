#include <allegro.h>
#include "tetrad.hpp"
#include "tilemap.hpp"


Tilemap::Tilemap(void) {
  clear();
}


void Tilemap::clear(void) {
  for (int i = 0; i != TILEMAP_W; ++i) {
    for (int j = 0; j != TILEMAP_H; ++j) {
      tilemap[i][j] = 0;
    }
  }
}


bool Tilemap::collision_check(int n, int x, int y, int z) const {
  for (int i = 0; i != TETRAD_W; ++i) {
    for (int j = 0; j != TETRAD_H; ++j) {
      if (TETRAD[n][z][i][j] &&
          (tilemap[x + i][y + j] ||
           x + i < 0 ||
           x + i >= TILEMAP_W ||
           y + j < 0 ||
           y + j >= TILEMAP_H)) {
        return false;
      }
    }
  }
  return true;
}


void Tilemap::put_tetrad(int n, int x, int y, int z) {
  // place tetrad on tilemap
  for (int i = 0; i != TETRAD_W; ++i) {
    for (int j = 0; j != TETRAD_H; ++j) {
      if (TETRAD[n][z][i][j] != 0) {
        tilemap[x + i][y + j] = col[n];
      }
    }
  }
  
  // for each row..
  for (int i = 0; i != TILEMAP_H; ++i) {
    // ..count the columns
    int count = 0;
    for (int j = 0; j != TILEMAP_W; ++j) {
      if (tilemap[j][i] != 0) {
        count++;
      }
    }
    // if line found, clear it
    if (count == TILEMAP_W) {
      // drop upper lines
      for (int j = 0; j != i; ++j) {
        for (int k = 0; k != TILEMAP_W; ++k) {
          tilemap[k][i-j] = tilemap[k][i-j-1];
        }
      }
    }
  }
}


void Tilemap::draw(BITMAP *bmp) {
  for (int i = 0; i != TILEMAP_W; ++i) {
    for (int j = 0; j != TILEMAP_H; ++j) {
      if (tilemap[i][j] != 0) {
        draw_tile(bmp, i, j, tilemap[i][j]);
      }
    }
  }
}
