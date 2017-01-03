#include "service_locator.h"
#include "message_queue.h"
#include "actor_factory.h"

MessageQueue* ServiceLocator::messageQueue_;
ActorFactory* ServiceLocator::actorFactory_;
