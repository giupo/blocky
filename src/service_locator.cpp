#include "service_locator.h"
#include "message_queue.h"
#include "actor_factory.h"
#include "component_factories.h"

MessageQueue* ServiceLocator::messageQueue_;
ActorFactory* ServiceLocator::actorFactory_;
ComponentFactory* ServiceLocator::componentFactory_;
