#include <SDL2/SDL.h>

#ifndef BALL_H
#define BALL_H

// SDL_Rect box;

typedef struct{
  int x;
  int y;
  int rad;
} Ball;

Ball ball_init();
void ball_update(Ball *ball);
void ball_draw(SDL_Renderer* renderer, Ball ball);



#endif
