#ifndef __LIFE_CYCLE__
#define __LIFE_CYCLE__

class LifeCycle {
public:
  /** 
   * @brief initialize a component
   */
  virtual void init() = 0;
  /**
   * @brief shutdown a component
   */
  virtual void shutdown() = 0;
};

class Updatable : public LifeCycle {
public:
  /** 
   * @brief updates object's state
   */
  virtual void update() = 0;
};

class Loopable : public LifeCycle {
  /**
   * @brief loops object life-cyle
   */
  virtual void loop() = 0;
};
  
#endif
