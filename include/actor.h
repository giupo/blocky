#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <vector>

#include "message_queue.h"
#include "tinyxml2.h"
#include "component.h"

class Actor {
 private:
  std::vector<BComponent*> *components;
  
 public:
  Actor();
  ~Actor();
  int init(tinyxml2::XMLNode* node);
  int destroy();
  void update();
  void onMessage(Message& msg);
};

#endif
