//========================================================================
// program name : simple.ino
// date/author  : 2022/04/24 v0.0.1 @chromlinux03
// date/update  : 2022/04/25 v0.0.2 Changed interrupt to pass a function pointer
// github       : https://github.com/chrmlinux/tinyTimeR
// Specifies the interrupt interval in microseconds
//========================================================================
#include "tinyTimeR.hpp"
static tinyTimeR tt;
#define LED_PIN (10)

//=========================================
// ledOnOff
//=========================================
void ledOnOff(void) {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

//=========================================
// setup
//=========================================
void setup(void) {
  Serial.begin(115200); delay(1000);
  pinMode(LED_PIN, OUTPUT);
  tt.begin(ledOnOff, 1000 * 24);
}

//=========================================
// loop
//=========================================
void loop(void) {}
