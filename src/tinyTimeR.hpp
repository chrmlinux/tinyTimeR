//========================================================================
// program name : tinyTimeR.hpp
// date/author  : 2022/04/24 @chromlinux03
// License      : MIT
// github       : https://github.com/chrmlinux/tinyTimeR
// update       : 2022/04/24 v0.0.1 @chromlinux03
//              : 2022/04/25 v0.0.2 Changed to interrupt pass a function pointer
// Specifies the interrupt interval in microseconds
//========================================================================
#ifndef _TINYTIMER_HPP_
#define _TINYTIMER_HPP_

#include <Arduino.h>

//========================================
// onTimer
//========================================
class tinyTimeR {

  public:

  //========================================
  // Constructor
  //========================================
  tinyTimeR(void) {}

  //========================================
  // begin
  //========================================
  uint16_t begin(void (*func)(), uint32_t timerUSec) {
    uint16_t rtn = 0;
    _timerUSec = timerUSec;
    _timer = timerBegin(0, 80, true);
    _exec = func;
    timerAttachInterrupt(_timer, _exec, true);
    timerAlarmWrite(_timer, _timerUSec, true);
    play();
    return rtn;
  }

  //========================================
  // end
  //========================================
  void end(void) {
  }

  //========================================
  // play
  //========================================
  void play(void) {
    timerAlarmEnable(_timer);
  }

  //========================================
  // disable
  //========================================
  void pause(void) {
    timerAlarmDisable(_timer);
  }

  private:
    void (*_exec)();

  //========================================
  // work
  //========================================
  uint32_t _timerUSec = 1000 * 1000;
  hw_timer_t *_timer = NULL;

};
#endif
