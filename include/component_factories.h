#ifndef __COMPONENT_FACTORIES_H__
#define __COMPONENT_FACTORIES_H__

#include <string>
#include <map>
#include "easylogging++.h"
#include "component.h"

typedef std::string ComponentTypeName; 

BComponent* test_me();

typedef BComponent* (*CreateFunction)(void);
typedef std::map<std::string, CreateFunction> FunctionMap;

class ComponentFactory {
private:
  FunctionMap creators_map;
public:
  ComponentFactory(): creators_map() {}
  ~ComponentFactory() {}
  void init();
  FunctionMap* getCreatorsMap() {
    return &creators_map;
  }
};

#endif
