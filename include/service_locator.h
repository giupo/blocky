#ifndef __SERVICE_LOCATOR_H__
#define __SERVICE_LOCATOR_H__

#include "message_queue.h"
#include "actor_factory.h"
#include "easylogging++.h"

class ServiceLocator {
 public:
  static MessageQueue* getMessageQueue() {
    return messageQueue_;
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
    LOG(DEBUG) << "ServiceLocator shutdown ended";
  }
  
 private:
  static MessageQueue* messageQueue_;
  static ActorFactory* actorFactory_;
};

#endif
