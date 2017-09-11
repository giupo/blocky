#ifndef __SERVICE_LOCATOR__
#define __SERVICE_LOCATOR__

#include "config4cpp/Configuration.h"
#include "spdlog/spdlog.h"
#include "SDL2/SDL.h"

using config4cpp::Configuration;

class ServiceLocator {
public:

  static void provide(SDL_Renderer* renderer) {
    renderer_ = renderer;
  }

  static SDL_Renderer* getRenderer() {
    return renderer_;
  }
  
  static void provide(Configuration* cfg) {
    cfg_ = cfg;
  }
  
  static Configuration& getConfiguration() {
    return *cfg_;
  }

  static void shutdown() {
    auto log = spdlog::get("ServiceLocator");
    log->info("ServiceLocator shutdown started");
    if(nullptr != cfg_) {
      cfg_->destroy();
      cfg_ = nullptr;
    }
    log->info("ServiceLocator shutdown ended");

    if(NULL != renderer_) {
      SDL_DestroyRenderer(renderer_);
      renderer_ = NULL;
    }
  }
private:
  static Configuration* cfg_;
  static SDL_Renderer* renderer_;
};

#endif
