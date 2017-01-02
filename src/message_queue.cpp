#include "message_queue.h"


MessageQueue::MessageQueue() {
  this->queue = new std::vector<Message*>();
}

MessageQueue::~MessageQueue() {
  delete this->queue;
}

int MessageQueue::add(Message* msg) {
  this->queue->push_back(msg);
}
