#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <actor.h>

class Command {
public:
  virtual ~Command() {}
  virtual void execute(Actor& actor) =0;
};

class MoveRightCommand : public Command {
public:
  virtual void execute(Actor& actor) {    
  }
};
  
class MoveLeftCommand : public Command {
public:
  virtual void execute(Actor& actor) { 
  }
};

class FireCommand : public Command {
public:
  virtual void execute(Actor& actor) {   
  }
};

#endif
