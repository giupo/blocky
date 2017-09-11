#include "ServiceLocator.h"

#include "SDL2/SDL.h"
#include "config4cpp/Configuration.h"


using config4cpp::Configuration;

Configuration* ServiceLocator::cfg_;
SDL_Renderer* ServiceLocator::renderer_;
