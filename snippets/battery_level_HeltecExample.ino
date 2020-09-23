/*
 * From Heltech Example
 * https://github.com/HelTecAutomation/Heltec_ESP32/blob/master/examples/ESP32/ADC_Read_Voltage/Battery_power/Battery_power.ino
 */
 
#include <Arduino.h>

#define MAXBATT 4200    // The default Lipo is 4200mv when the battery is fully charged.
#define MINBATT 3200    // The default Lipo is 3200mv when the battery is empty...this WILL be low on the 3.3v rail specs!
#define VOLTAGE_DIVIDER 3.20    // Board has 220k/100k voltage divider
#define VBATT_SAMPLE 500     // Battery sample rate in ms
#define VBATT_SMOOTH 50      // Number of averages in sample
#define ADC_READ_STABILIZE 5       // in ms (delay from GPIO control and ADC connections times)
#define VEXT_GPIO 21      // Heltec GPIO to toggle Vext off and allow VBatt read connection
#define VBATT_GPIO 37 // Heltec GPIO for reading Vbatt on wifi kit 32




uint16_t readBattLevel() { 
  static uint8_t idx = 0;
  static uint16_t readings[VBATT_SMOOTH];
  static int32_t total = 0;
  static bool f = true; // first run flag
  if(f){ for(uint8_t c=0;c<VBATT_SMOOTH;c++){ readings[c]=0; } f=false; }   // Initialize the samples array first run
  total = total - readings[idx];  // subtract the last reading to get ready for new reading
  
  //adcStart(VBATT_GPIO);
  //while(adcBusy(VBATT_GPIO));
  uint16_t newreading = analogRead(VBATT_GPIO); // read from the analog battery pin
  //adcEnd(37);
  
  readings[idx] = newreading * 3300 / 4095 * VOLTAGE_DIVIDER;  // scale to mV from ADC and undo voltage divider to battery
  Serial.printf("ADC Raw Reading[%d]: %d mV", newreading, readings[idx]);
  Serial.println("");
  
  total = total + readings[idx];
  idx++;
  if (idx >= VBATT_SMOOTH) { idx=0; } // Check if idx is past the end of buffer, if so then reset
  
  uint16_t voltage = round(((float)total / 1000.0 / (float)VBATT_SMOOTH));
  Serial.printf("Battery Voltage (avg): ");
  Serial.println(voltage);
  
  return voltage;  
}


void setup()
{

   Serial.begin(115200);
   
  //adcAttachPin(VBATT_GPIO); // Used to read voltage from battery
  for (uint8_t i = 0;i < VBATT_SMOOTH;i++) {
    readBattLevel();
  }
}

void loop()
{
  uint16_t batt_v = readBattLevel();
  delay(5000);
}
