#ifndef __ACTOR_FACTORY_H__
#define __ACTOR_FACTORY_H__

#include <map>
#include <string>

#include "component_factories.h"
 
typedef unsigned long ActorId;
typedef std::map<std::string, CreateFunction> CreatorMap;
typedef std::string ActorName;

class ActorFactory {
 private:
  ActorId nextId;
  CreatorMap creatorMap;
 public:
  ActorFactory(): nextId(0) {
   creatorMap = {
     { "test_me", &test_me } 
   };
   creatorMap["test_me"]();
  }
  ~ActorFactory() {}

  
};

#endif
