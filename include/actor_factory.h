#ifndef __ACTOR_FACTORY_H__
#define __ACTOR_FACTORY_H__

#include <map>
#include <string>
#include <memory>

#include "tinyxml2.h"
#include "component_factories.h"
#include "actor.h"

typedef std::map<ComponentTypeName, CreateFunction> CreatorMap;
typedef std::shared_ptr<Actor> StrongActorPtr;
typedef std::weak_ptr<Actor> WeakActorPtr;
typedef std::shared_ptr<BComponent> StrongActorComponentPtr;
typedef std::weak_ptr<BComponent> WeakActorComponentPtr;

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
  
  /** 
   *
   * @brief Creates an Actor from XML
   * 
   * @param node XML node containing config info
   * 
   * @return a pointer to an Actor 
   */
  StrongActorPtr create(tinyxml2::XMLNode *node);
};

#endif
