#include "Game.h"

#include "SDL2/SDL.h"
#include "SDL_image.h"

#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

#include "spdlog/spdlog.h"

void BlockyGame::init(config4cpp::Configuration* cfg) {
  //Will parse some config.
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Hello World!", 0, 0, 640, 480, 0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  surface = IMG_Load("texture.png");
  texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void BlockyGame::loop() {
  auto log = spdlog::get("Game");
  running = true;
  SDL_Event event;

  while (running) {
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
	log->debug("got SDL_QUIT message");
	running = false;
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }
}

void BlockyGame::shutdown() {
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
}
