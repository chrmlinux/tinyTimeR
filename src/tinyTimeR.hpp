//============================= tinyTimeR.hpp
//========================================================================
// program name : tinyTimeR.hpp
// date/author  : 2022/04/24 @chromlinux03
// License      : MIT
// github       : https://github.com/chrmlinux/tinyTimeR
//========================================================================
#ifndef _TINYTIMER_HPP_
#define _TINYTIMER_HPP_

#include <Arduino.h>

//========================================
// onTimer
//========================================
IRAM_ATTR void onTimerExec(void);

class tinyTimeR {

  public:

  //========================================
  // Constructor
  //========================================
  tinyTimeR(void) {
    
  }

  //========================================
  // begin
  //========================================
  uint16_t begin(uint32_t timerUSec) {
    uint16_t rtn = 0;
    _timerUSec = timerUSec;
    _timer = timerBegin(0, 80, true);
    timerAttachInterrupt(_timer, &onTimerExec, true);
    timerAlarmWrite(_timer, _timerUSec, true);
    timerAlarmEnable(_timer);
    return rtn;
  }

  //========================================
  // end
  //========================================
  void end(void) {
  }

  private:

  //========================================
  // work
  //========================================
  uint32_t _timerUSec = 1000 * 1000;
  hw_timer_t *_timer = NULL;

};
#endif
//============================= tinyTimeR.hpp
