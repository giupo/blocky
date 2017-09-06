#include "service_locator.h"

#include <config4cpp/Configuration.h>

#include "message_queue.h"
#include "actor_factory.h"
#include "component_factories.h"
#include "screen.h"
#include "resource.h"
#include "spdlog/spdlog.h"

using config4cpp::Configuration;

MessageQueue* ServiceLocator::messageQueue_;
ActorFactory* ServiceLocator::actorFactory_;
ComponentFactory* ServiceLocator::componentFactory_;
Screen* ServiceLocator::screen_;

//ResourceManager* ServiceLocator::resourceManager_;
Configuration* ServiceLocator::configuration_;
