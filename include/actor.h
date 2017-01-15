#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <vector>
#include <string>

#include "message_queue.h"
#include "tinyxml2.h"
#include "component.h"

typedef unsigned long ActorId;
typedef std::string ActorName;

class Actor {
private:
  std::vector<BComponent*> *components;
  ActorId id;
  ActorName name;
public:
  Actor(ActorId id_, ActorName name_): id(id_), name(name_) {
      components = new std::vector<BComponent*>();
  }; 

  ~Actor();
  int init(tinyxml2::XMLNode* node);
  /**
     @brief destroys eveyrhing related to this Actor
  */
  int destroy();
  void update();
  void onMessage(Message& msg);

  ActorId getId() {
    return id;
  }
};

#endif
