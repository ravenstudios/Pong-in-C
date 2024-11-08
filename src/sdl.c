#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "globals.h"
#include "ball.h"
#include "paddle.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

Ball ball;
Paddle player1;
Paddle player2;



int sdl_init(){
  // Initialize SDL
  ball = ball_init();
  player1 = paddle_init(0);
  player2 = paddle_init(WINDOW_WIDTH - PADDLE_WIDTH);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
      return 1;
  }

  // Create an SDL window
  window = SDL_CreateWindow("Draw a Box",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT,
                                        SDL_WINDOW_SHOWN);
  if (window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      SDL_Quit();
      return 1;
  }

  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
      printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
  }
  return 0;
}

void sdl_update(){
  ball_update(&ball);
  paddle_update(&player1);
  paddle_update(&player2);
}


void sdl_draw(){
  sdl_update();
  ball_draw(renderer, &ball);
  paddle_draw(renderer, &player1);
  paddle_draw(renderer, &player2);

  // SDL_RenderFillRect(renderer, &box);
}

// Main loop flag



void sdl_main_loop(){
  bool quit = false;
  SDL_Event e;

  while (!quit) {
      // Handle events
      while (SDL_PollEvent(&e) != 0) {
          if (e.type == SDL_QUIT) {
              quit = true;
          }
      }

      // Clear the screen with a black color
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      // Set the color for the box (e.g., red)
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

      sdl_draw();

      // Draw the box


      // Update the screen
      SDL_RenderPresent(renderer);
      SDL_Delay(16);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

}
// Main loop

void quit(){

}
