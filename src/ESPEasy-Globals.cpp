#include <Arduino.h>

#include "ESPEasy-Globals.h"
#include "ESPEasy_plugindefs.h"


#if defined(ESP32)
  int8_t ledChannelPin[16];
#endif


I2Cdev i2cdev;




boolean printToWeb = false;
String printWebString;
boolean printToWebJSON = false;



unsigned long timermqtt_interval = 250;
unsigned long lastSend = 0;
unsigned long lastWeb = 0;
byte cmd_within_mainloop = 0;
unsigned long wdcounter = 0;
unsigned long timerAPoff = 0;    // Timer to check whether the AP mode should be disabled (0 = disabled)
unsigned long timerAPstart = 0;  // Timer to start AP mode, started when no valid network is detected.
unsigned long timerAwakeFromDeepSleep = 0;


#if FEATURE_ADC_VCC
float vcc = -1.0;
#endif
int lastADCvalue = 0;

boolean WebLoggedIn = false;
int WebLoggedInTimer = 300;


String dummyString = "";  // FIXME @TD-er  This may take a lot of memory over time, since long-lived Strings only tend to grow.






bool shouldReboot(false);
bool firstLoop(true);

boolean activeRuleSets[RULESETS_MAX];

boolean UseRTOSMultitasking(false);
