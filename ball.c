#include <SDL2/SDL.h>
#include "ball.h"
#include "globals.h"


int speed = 10;

Ball ball_init(){
  Ball ball;
  ball.x = 0;
  ball.y = 0;
  ball.rad = 50;
  return ball;
}

// box.x = 0;   // X position
// box.y = 0;   // Y position
// box.w = 100;   // Width
// box.h = 300;   // Height





void ball_update(Ball *ball){
  ball->x += speed;
  if(ball->x + ball->rad > WINDOW_WIDTH || ball->x < 0){
    speed = -speed;
  }

}

void ball_draw(SDL_Renderer* renderer, Ball ball){
  SDL_Rect box;
  box.x = ball.x;
  box.y = ball.y;
  box.w = ball.rad;
  box.h = ball.rad;
  SDL_RenderFillRect(renderer, &box);
}
