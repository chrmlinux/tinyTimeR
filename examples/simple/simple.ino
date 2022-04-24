//========================================================================
// program name : simple.ino
// date/author  : 2022/04/24 @chromlinux03
//========================================================================
#include <tinyTimeR.hpp>
static tinyTimeR tr;
#define LED_PIN (10)

//=========================================
// Processing executed when a 
// timer interrupt is applied
//=========================================
void IRAM_ATTR onTimerExec(void) {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

//=========================================
// setup
//=========================================
void setup(void) {
  Serial.begin(115200); delay(1000);
  pinMode(LED_PIN, OUTPUT);
  tr.begin(1000 * 100); // Specifies the interrupt interval in microseconds
}

//=========================================
// loop
//=========================================
void loop(void) {}
