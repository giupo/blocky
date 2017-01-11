#ifndef __COMPONENT_FACTORIES_H__
#define __COMPONENT_FACTORIES_H__

#include <string>
#include <map>
#include "easylogging++.h"
#include "component.h"

typedef std::string ComponentTypeName; 
typedef Component* (*CreateFunction)(void);

BComponent* test_me();

typedef BComponent* (*CreateFunction)(void);
typedef std::map<std::string, CreateFunction> FunctionMap;

static FunctionMap creators_map;
void setupCreators();

#endif
