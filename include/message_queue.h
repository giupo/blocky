#ifndef __MESSAGE_QUEUE__
#define __MESSAGE_QUEUE__

#include <vector>

typedef struct {
  int type;
  void* data;
} Message;

class MessageQueue {
 private:
  std::vector<Message*> queue;
 public:
  MessageQueue(): queue() {}
  ~MessageQueue() {}
  int add(Message* msg);
};

#endif
