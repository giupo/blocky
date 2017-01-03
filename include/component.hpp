#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <vector>

#include "message_queue.h"
#include "tinyxml2.h"

typedef unsigned long ComponentId;

class Component {
 private:
  ComponentId id;
  
 public:

  ComponentId getId() {
    return this->id;
  }
  
  virtual int init(tinyxml2::XMLNode* node) =0;
  virtual int destroy() =0;
  virtual void onMessage(Message& msg) =0;
  virtual void update() =0;
};

#endif
