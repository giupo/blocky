#ifndef __SERVICE_LOCATOR_H__
#define __SERVICE_LOCATOR_H__

#include "message_queue.h"

class ServiceLocator {
 public:
  static MessageQueue* getMessageQueue() {
    return messageQueue_;
  }

  static void provide(MessageQueue* messageQueue) {
    messageQueue_ = messageQueue;
  }

 private:
  static MessageQueue* messageQueue_;
};

MessageQueue* ServiceLocator::messageQueue_;

#endif
