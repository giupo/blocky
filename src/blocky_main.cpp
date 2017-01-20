#include <iostream>

#include <SDL2/SDL.h>
#include <chipmunk.h>

#include <config4cpp/Configuration.h>

#if defined(__LINUX__) || defined(__APPLE__)
#include <csignal>
#endif

#include <map>

#include "blocky_main.h"
#include "game.h"
#include "tinyxml2.h"
#include "blocky_macros.h"
#include "easylogging++.h"
#include "component_factories.h"
#include "actor_factory.h"
#include "service_locator.h"
#include "screen.h"

using namespace tinyxml2;
using config4cpp::Configuration;

/**
 * @brief App main entry
 */

int blocky_main(int argc, char **argv) {
  //Setup Service Locator:
  ServiceLocator::provide(new ComponentFactory());
  ServiceLocator::provide(new MessageQueue());
  ServiceLocator::provide(new ActorFactory());
  ServiceLocator::provide(new Screen());
  ServiceLocator::provide(Configuration::create());
  // Loading XML config file
  // TODO: Deve essere sostituito con un ResourceFile unico
  XMLDocument xmlDoc;
  XMLError eResult = xmlDoc.LoadFile("config.xml");
  XMLCheckResult(eResult);
  
  LOG(DEBUG) << "Hello!!!";

  XMLNode* pRoot = xmlDoc.FirstChild();
  if (nullptr == pRoot) {
    LOG(ERROR) << "XML root element is nullptr";
    return XML_ERROR_FILE_READ_ERROR;
  }

  ServiceLocator::getComponentFactory()->init();

  Game g(true, 60);

  if(g.init(pRoot)) {
    LOG(ERROR) << "Cannot init game";
  }

  int rc = g.loop();
  return rc;
}


