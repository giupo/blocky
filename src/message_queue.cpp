#include "message_queue.h"

int MessageQueue::add(Message* msg) {
  queue.push_back(msg);
  return 0;
}
