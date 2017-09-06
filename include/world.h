#ifndef __WORLD_H__
#define __WORLD_H__

#include <chipmunk/chipmunk.h>
#include <config4cpp/Configuration.h>

using config4cpp::Configuration;


class World {
private:
  cpVect gravity;
  cpSpace* space;
  float step;
public:
  World();
  ~World();

  void init(Configuration* cfg);
  void update();
  void shutdown();

  void setGravity(float x, float y);
  void setGravity(cpVect& gravity);
};


#endif
