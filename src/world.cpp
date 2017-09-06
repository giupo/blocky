#include "world.h"

#include "chipmunk/chipmunk.h"

World::World() {
  space = NULL;
  gravity = cpv(0, 0);
  step = .0;
}

World::~World() {
}


void World::init(Configuration* cfg) {
  space = cpSpaceNew();
  gravity = cpv(0.f, 0.f);
  step = 1./60.;
  this->setGravity(0, 0);
}

void World::shutdown() {
  if (NULL != space) {
    cpSpaceFree(space);
  }
}


void World::setGravity(float x, float y) {
  gravity = cpv(x, y);
  cpSpaceSetGravity(space, gravity);
}

void World::setGravity(cpVect& gravity) {
  this->gravity = cpv(gravity.x, gravity.y);
  cpSpaceSetGravity(space, this->gravity);
}

void World::update() {
  cpSpaceStep(space, step);
}


