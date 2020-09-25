/*
 * Display routine. From Heltec examples
 *
 * https://github.com/HelTecAutomation/Heltec_ESP32/blob/master/examples/OLED/SSD1306SimpleDemo/SSD1306SimpleDemo.ino
*/


#include "Arduino.h"
#include "heltec.h"
#include "icons.h"

void setup() {

  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);



  //Heltec.display->flipScreenVertically();
  //Heltec.display->setFont(ArialMT_Plain_10);
  //Heltec.display->invertDisplay();
  //Heltec.display->drawXbm(0, 0, signal_bars_w, signal_bars_h, signal_zerobarsx_16);
  //Heltec.display->display();

}


void drawBattery(uint8_t batt) {
  //Heltec.display->setColor(WHITE);
  Heltec.display->drawRect(104, 0, 24, 15);
  Heltec.display->drawRect(99, 5, 5, 5);
  Heltec.display->fillRect(112, 2, 10, 13);
}

void drawTemperature() {
  
    Heltec.display->drawXbm(0, 17, thermometer_48_w, thermometer_48_h, thermometer_48);
    Heltec.display->drawXbm(thermometer_48_w, 17, thermometer_24_w, thermometer_24_h, thermometer_24_g);
    Heltec.display->drawXbm(thermometer_48_w+thermometer_24_w+2, 17, thermometer_24_w, thermometer_24_h, thermometer_24);

    //Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    //Heltec.display->setFont(ArialMT_Plain_24);
    //Heltec.display->drawString(thermometer_20_w + 1, 17, "23");
    //uint8_t temp_w = Heltec.display->getStringWidth("23");
    //Heltec.display->setFont(ArialMT_Plain_10);
    //Heltec.display->drawString(thermometer_20_w + temp_w + 2, 17, ".5 C");
}



void loop() {
  // clear the display
  Heltec.display->clear();

  drawBattery(25);
  drawTemperature();
  //Heltec.display->setColor(WHITE);
  Heltec.display->drawXbm(0, 0, signal_bars_w, signal_bars_h, signal_fourbars_16);
  Heltec.display->drawXbm(signal_bars_w+2, 0, signal_bars_w, signal_bars_h, signal_threebars_16);
  Heltec.display->drawXbm(signal_bars_w*2+2, 0, signal_bars_w, signal_bars_h, signal_zerobarsx_16);
  Heltec.display->display();

  delay(10000);
}
