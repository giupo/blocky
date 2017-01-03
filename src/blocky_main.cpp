#include <iostream>

#include <SDL2/SDL.h>
#include <chipmunk.h>

#if defined(__LINUX__) || defined(__APPLE__)
#include <csignal>
#endif

#include <map>

#include "blocky_main.h"
#include "game.h"
#include "tinyxml2.h"
#include "blocky_macros.h"
#include "easylogging++.h"

using namespace tinyxml2;

int blocky_main(int argc, char **argv) {

  Game g;
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

  if(g.init(pRoot)) {
    LOG(ERROR) << "Cannot init game";
  }
  int rc = g.loop();
  return rc;
}


