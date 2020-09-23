# tomato-stm32

## Development Board

### Specifications

|Specifications| |
|---|---|
|Board Name|[WiFi Kit 32](https://heltec.org/project/wifi-kit-32/)|
|Board Version|2.1|
|Processor|ESP32|
|Vendor|KeeYees|
|Manufacturer|[Heltec](https://heltec.org/) (repackaged and sole by (KeeYees)|
|Purchase Listing|[Amazon Listing](https://www.amazon.ca/KeeYees-Internet-Development-Display-Bluetooth/dp/B07THGMMV8/ref=pd_sbs_147_6/140-6580263-6671007?_encoding=UTF8&pd_rd_i=B07THGMMV8&pd_rd_r=467c3fdd-7af4-496f-b44f-b92d0cae06b9&pd_rd_w=RoQUI&pd_rd_wg=htgSs&pf_rd_p=e2c8fd77-bcab-46e7-9a0c-48650e9db03b&pf_rd_r=Z67XHGQ235C03ZY56FTN&refRID=Z67XHGQ235C03ZY56FTN&th=1)|

## Drawings

|Drawings|  |
|---|---|
|Pinout Diagram|[PDF CAD Version](https://resource.heltec.cn/download/WiFi_Kit_32/WIFI_Kit_32_pinoutDiagram_V2.1.pdf)|
|Schematic|[PDF CAD Version](https://resource.heltec.cn/download/WiFi_Kit_32/WIFI_Kit_32_Schematic_diagram_V2.1.PDF)|

## Source Code

|Board Specific|  |
|---|---|
|Wifi Kit 32|[github](https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series)|
|Heltec ESP32 - General|[github](https://github.com/HelTecAutomation/Heltec_ESP32)|
|Heltec ESP32 - OLED API|[github](https://github.com/HelTecAutomation/Heltec_ESP32/blob/master/src/oled/API.md)|


## Power

  * Battery voltage is on `GPIO13` aka `ADC2_4`

### Power External Components

 * Use pin `Vext` to supply regulated 3.3V to external components
 * Use `GPIO21` to turn on or off power to components being powered by `Vext` (To save power while asleep). Active low.
   * Turn ON: `digitalWrite(21, LOW);`
   * Turn OFF: `digitalWrite(21, HIGH);`

## Notes

  * 12bit ADC; values 0-4095
  * When using Wifi, `ADC2` analog inputs are not available. [Espressif Docs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/adc.html)

analogSetAttenuation(attenuation): sets the input attenuation for all ADC pins. Default is ADC_11db. Accepted values:
  * `ADC_0db`: sets no attenuation (1V input = ADC reading of 1088)
  * `ADC_2_5db`: sets an attenuation of 1.34 (1V input = ADC reading of 2086).
  * `ADC_6db`: sets an attenuation of 1.5 (1V input = ADC reading of 2975).
  * `ADC_11db`: sets an attenuation of 3.6 (1V input = ADC reading of 3959).

## Other Documentation

|General|  |
|---|---|
|Heltec Generic Docs|[heltec-automation-docs.readthedocs.io](https://heltec-automation-docs.readthedocs.io/en/latest/esp32+arduino/index.html)|
|Heltec Forums|[community.heltec.cn](http://community.heltec.cn/)|
|Espressif ESP 32|[CPU]([Espressif Docs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/index.html)|
