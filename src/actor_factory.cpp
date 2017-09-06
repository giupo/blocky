#include "actor_factory.h"
#include "constants.h"
#include "tinyxml2.h"
#include "spdlog/spdlog.h"

StrongActorPtr ActorFactory::create(tinyxml2::XMLNode *node) {
  tinyxml2::XMLElement* elem = node->ToElement();
  if(std::string(elem->Name()).compare(ACTOR_NAME_XML) != 0) {
    spdlog::get("main")->debug("XMLElement is not an {} : {}", ACTOR_NAME_XML, elem->Name());
    return nullptr;
  }
  ActorId id = ++nextId;
  ActorName actorName = elem->Attribute(ACTOR_NAME_ATTRIBUTE_XML);
  StrongActorPtr actor(new Actor(id, "CIPPA"));
  return actor;
}
