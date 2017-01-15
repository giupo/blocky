#include "service_locator.h"
#include "message_queue.h"
#include "actor_factory.h"
#include "component_factories.h"
#include "screen.h"
#include "resource.h"

MessageQueue* ServiceLocator::messageQueue_;
ActorFactory* ServiceLocator::actorFactory_;
ComponentFactory* ServiceLocator::componentFactory_;
Screen* ServiceLocator::screen_;
//ResourceManager* ServiceLocator::resourceManager_;
