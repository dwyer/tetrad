#ifndef __TILEMAP_H__
#define __TILEMAP_H__

#include "image.hpp"


const int TILEMAP_W = 8;
const int TILEMAP_H = 12;


class Tilemap : public Image {
  private:
    int tilemap[TILEMAP_W][TILEMAP_H];
  
  public:
    Tilemap(void);
    void clear(void);
    bool collision_check(int n, int x, int y, int z) const;
    void put_tetrad(int n, int x, int y, int z);
    void draw(BITMAP *bmp);
};


#endif
