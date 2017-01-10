#include <iostream>

#include <SDL2/SDL.h>
#include <chipmunk.h>

#if defined(__LINUX__) || defined(__APPLE__)
#include <csignal>
#endif

#include "blocky_main.h"
#include "game.h"
#include "tinyxml2.h"
#include "easylogging++.h"
#include "component_factories.h"
#include <map>
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { \
  printf("Error: %i\n", a_eResult); return a_eResult;			\
 }
#endif

using namespace tinyxml2;

BComponent* test_me() {
  LOG(DEBUG) << "Called!";
  return nullptr;
}


/**
 * @brief App main entry
 */

int blocky_main(int argc, char **argv) {
  // Loading XML config file
  // TODO: Deve essere sostituito con un ResourceFile unico
  XMLDocument xmlDoc;
  XMLError eResult = xmlDoc.LoadFile("config.xml");
  XMLCheckResult(eResult);

  XMLNode* pRoot = xmlDoc.FirstChild();

  if (nullptr == pRoot) {
    LOG(ERROR) << "XML root element is nullptr";
    return XML_ERROR_FILE_READ_ERROR;
  }
  setupCreators();
  
  creators_map["test_me"]();
  Game g;
  if(g.init(pRoot)) {
    LOG(ERROR) << "Cannot init game";
  }
  return g.loop();
}


