#ifndef __BLOCKY_MACROS_H__
#define __BLOCKY_MACROS_H__

#include "tinyxml2.h"

using namespace tinyxml2;



#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) {       \
    std::cerr << "Error: " << a_eResult << std::endl; return a_eResult; \
  }
#endif

#endif
