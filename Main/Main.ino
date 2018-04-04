#include <Wire.h>

#define BAUD_RATE 9600

// Flags to enable/disable manually
//#define DEBUG_LIGHT
//#define DEBUG_COMPASS
//#define DEBUG_LOCOMOTION
#define DEBUG_US

//#define IS_STRIKER

void setup() {
  Serial.begin(BAUD_RATE);

  Serial.print("Setting up Main for the ");
#ifdef IS_STRIKER
  Serial.println("striker.");
#else
  Serial.println("goalkeeper.");
#endif

  Wire.begin();

  InitGate();
  InitLoc();
  InitLight();
  InitSld();
  InitCmp();
  InitUS();

  Serial.println("Main Setup complete.");
}

void loop() {
  ReadLight();
  ReadPosition();

#ifdef IS_STRIKER
  strikerLoop();
#else
  goalieLoop();
#endif
}

#ifdef IS_STRIKER
void strikerLoop() {

}
#else
void goalieLoop() {
  
}
#endif
