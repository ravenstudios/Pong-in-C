#include <SDL2/SDL.h>
#include "ball.h"
#include "globals.h"


int x_speed = 10;
int y_speed = 10;

Ball ball_init(){
  Ball ball;
  ball.x = 0;
  ball.y = 0;
  ball.rad = 50;
  return ball;
}


void ball_update(Ball *ball){
  ball->x += x_speed;
  ball->y += y_speed;

  if(ball->x + ball->rad > WINDOW_WIDTH || ball->x < 0){
    x_speed = -x_speed;
  }

  if(ball->y +ball->rad > WINDOW_HEIGHT || ball->y < 0){
    y_speed = -y_speed;
  }
}

void ball_draw(SDL_Renderer* renderer, Ball *ball){
  SDL_Rect box;
  box.x = ball->x;
  box.y = ball->y;
  box.w = ball->rad;
  box.h = ball->rad;
  SDL_RenderFillRect(renderer, &box);
}
