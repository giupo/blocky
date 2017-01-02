#ifndef __COMPONENT_FACTORIES_H__
#define __COMPONENT_FACTORIES_H__

#include <string>
#include <map>
#include "easylogging++.h"
#include "component.h"

typedef Component* (*CreateFunction)(void);
typedef std::map<std::string, CreateFunction> FunctionMap;

Component* test_me();
static FunctionMap creators_map;
#endif
