#ifndef __IMAGE_H__
#define __IMAGE_H__


const int TILE_SZ = 16;


class Image {
  protected:
    static int col[7];
    void draw_tile(BITMAP *bmp, int x, int y, int col);
  
  public:
    static void init_color(void);
    virtual void draw(BITMAP *bmp) = 0;
};

#endif
