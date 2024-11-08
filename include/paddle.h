#include <SDL2/SDL.h>

#ifndef PADDLE_H
#define PADDLE_H

// SDL_Rect box;

typedef struct{
  int x;
  int y;
  int w;
  int h;
  int speed;
} Paddle;

Paddle paddle_init();
void paddle_update(Paddle *paddle);
void paddle_draw(SDL_Renderer* renderer, Paddle *paddle);



#endif
