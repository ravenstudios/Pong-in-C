#include <SDL2/SDL.h>
#include "paddle.h"
#include "globals.h"





Paddle paddle_init(int x){
  Paddle paddle;
  paddle.x = x;
  paddle.y = 0;
  paddle.w = PADDLE_WIDTH;
  paddle.h = PADDLE_HEIGHT;
  paddle.speed = 10;
  return paddle;
}


void paddle_update(Paddle *paddle){
  paddle->y += paddle->speed;

  if(paddle->y < 0 || paddle->y + paddle->h > WINDOW_HEIGHT){
    paddle->speed = -paddle->speed;
  }
}

void paddle_draw(SDL_Renderer* renderer, Paddle *paddle){
  SDL_Rect box;
  box.x = paddle->x;
  box.y = paddle->y;
  box.w = paddle->w;
  box.h = paddle->h;
  SDL_RenderFillRect(renderer, &box);
}
