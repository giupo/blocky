#ifndef __SERVICE_LOCATOR_H__
#define __SERVICE_LOCATOR_H__

#include "message_queue.h"
#include "actor_factory.h"
#include "easylogging++.h"

/**
 * @brief Class providing Factories and "singletons" (not-singletons)
 * 
 * Mainly this class offers a bunch of `provide` methods and `get`
 * methods for retrieving classes that we want to behave as Singleton
 */

class ServiceLocator {
public:
  
  /** 
   * @brief return a pointer to MessageQueue
   * @return a pointer to MessageQueue
   */
  static MessageQueue* getMessageQueue() {
    return messageQueue_;
  }
  
  /** 
   * @brief return a pointer to ActorFactory
   * @return a pointer to ActorFactory
   */
  static ActorFactory* getActorFactory() {
    return actorFactory_;
  }

  
  static void provide(ComponentFactory* componentFactory) {
    componentFactory_ = componentFactory;
  }
  
  /** 
   * @brief return a pointer to ComponentFactory
   * @return a pointer to ComponentFactory
   */
  static ComponentFactory* getComponentFactory() {
    return componentFactory_;
  }
  
  static void provide(MessageQueue* messageQueue) {
    messageQueue_ = messageQueue;
  }

  static void provide(ActorFactory* actorFactory) {
    actorFactory_ = actorFactory;
  }

  static void shutdown() {
    LOG(DEBUG) << "ServiceLocator shutdown started";

    if (actorFactory_) {
      delete actorFactory_;
      actorFactory_ = nullptr;
    }
    
    if (messageQueue_) {
      delete messageQueue_;
      messageQueue_ = nullptr;
    }

    if (componentFactory_) {
      delete componentFactory_;
      componentFactory_ = nullptr;
    }
    
    LOG(DEBUG) << "ServiceLocator shutdown ended";
  }
  
 private:
  static MessageQueue* messageQueue_;
  static ActorFactory* actorFactory_;
  static ComponentFactory* componentFactory_;
};

#endif
