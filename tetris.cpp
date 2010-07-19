#include <allegro.h>
#include "tetris.hpp"


void inc(void *i) {
  (*(volatile int *)i)++;
}

END_OF_FUNCTION(timer);


Tetris::Tetris(void) {
  int w = TILEMAP_W * TILE_SZ;
  int h = TILEMAP_H * TILE_SZ;
  tick = 0;
  
  allegro_init();
  install_keyboard();
  
  // set timer
  install_timer();
  LOCK_FUNCTION(inc);
  LOCK_VARIABLE(tick);
  install_param_int_ex(inc, (void *)&tick, BPS_TO_TIMER(100));
  srand(time(NULL));
  
  // set gfx
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, w, h, 0, 0);
  bmp = create_bitmap(SCREEN_W, SCREEN_H);
  Image::init_color();
}


Tetris::~Tetris(void) {
  remove_param_int(inc, (void *)&tick);
  destroy_bitmap(bmp);
  allegro_exit();
}


void Tetris::play(void) {
  while (!key[KEY_ESC]) {
    // input
    if (tick > 0) {
      if (keypressed()) {
        int k = readkey() >> 8;
        if (k == KEY_RIGHT) {
          tetrad.move(tilemap, 1, 0, 0);
        }
        else if (k == KEY_LEFT) {
          tetrad.move(tilemap, -1, 0, 0);
        }
        else if (k == KEY_DOWN) {
          tetrad.move(tilemap, 0, 1, 0);
        }
        else if (k == KEY_UP) {
          tetrad.move(tilemap, 0, 0, 1);
        }
        else if (k == KEY_SPACE) {
          tetrad.drop(tilemap);
        }
        else if (k == KEY_DEL) {
          tetrad.init();
          tilemap.clear();
        }
      }
      tetrad.update(tilemap);
      tick--;
    }
    // output
    clear_to_color(bmp, makecol(0, 0, 0));
    tilemap.draw(bmp);
    tetrad.draw(bmp);
    blit(bmp, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
  }
}
