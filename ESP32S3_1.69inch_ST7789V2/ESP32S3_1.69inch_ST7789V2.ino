/*
* Example project - ESP32-S3 with 1.69" 240x280 RGB ST7789 display.
* (c)2026 mzabovsky
* 
* Board and peripherals:
*   - Waveshare ESP32-S3-DEV-KIT-N32R16 -> https://docs.waveshare.com/ESP32-S3-DEV-KIT-N8R8
*   - Waveshare 1.69” 240x280 RGB IPS ST7789V2 -> https://www.waveshare.com/1.69inch-tft-module.htm?srsltid=AYCX9vID-5ex6a00Zwb7QWUnkV4MBa0fgjmRN6wswLQrYDksEHFVM7xw
*
* Firmware flash (single monolithic firmware):
*   -  firmware -> https://docs.waveshare.com/ESP32-S3-DEV-KIT-N8R8/Resources-And-Documents 
*   % esptool --chip esp32s3 --port /dev/cu.XXXXXX erase-flash
*   % esptool --chip esp32s3 --port /dev/cu.XXXXXX write-flash -z 0x0 Waveshare_N16R8.bin 
*
* Arduino IDE settings:
*   - Board: "ESP32S3 Dev Module Octal (WROOM2)"
*   - USB CDC On Boot: "Enabled"
*   - Flash Mode: "OPI 80MHz"
*   - Upload Speed: "115200"
*
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_WIDTH   240
#define TFT_HEIGHT  280

#define TFT_MOSI    11  // SDA
#define TFT_CLK     12  // SCL
#define TFT_CS      9   // CS
#define TFT_DC      10  // DC
#define TFT_RST     14  // RES
#define TFT_BL      13  // BLK

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


void setup() {
  Serial.begin(115200);
  while(!Serial);

  Serial.println(); Serial.println();
  Serial.println("ST7789 Test");
  Serial.println("-----------------------------------------------------");

  tft.init(TFT_WIDTH, TFT_HEIGHT, SPI_MODE0);
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);
  
  Serial.println("Display initialized.");
  //Serial.println(ST7735_MADCTL_BGR);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10,20);
  tft.println("ST7789 Test.");
  
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.setCursor(10,60);
  tft.println("Color test (GREEN)...");

  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.setCursor(10,75);
  tft.println("Color test (RED)...");

  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(1);
  tft.setCursor(10,90);
  tft.println("Color test (BLUE)...");

}

void loop() {
  // put your main code here, to run repeatedly:

}
