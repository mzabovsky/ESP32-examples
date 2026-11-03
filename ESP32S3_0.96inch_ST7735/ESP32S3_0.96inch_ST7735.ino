/*
* Example project - ESP32-S3 with 0.96" 80x160 RGB ST7735 display.
* (c)2026 mzabovsky
* 
* Board and peripherals:
*   - Waveshare ESP32-S3-DEV-KIT-N32R16 -> https://docs.waveshare.com/ESP32-S3-DEV-KIT-N8R8
*   - 0.96” 80x160 RGB IPS 4 SPI ICST7735S -> https://www.lcdwiki.com/0.96inch_IPS_Module
*
* Firmware flash (single monolithic firmware):
*   -  firmware -> https://docs.waveshare.com/ESP32-S3-DEV-KIT-N8R8/Resources-And-Documents 
*   % esptool --chip esp32s3 --port /dev/cu.XXXXXX erase-flash
*   % esptool --chip esp32s3 --port /dev/cu.XXXXXX write-flash -z 0x0 Waveshare_N16R8.bin 
*
* Arduino IDE settings:
*   - Board: "ESP32S3 Dev Module Octal (WROOM2)"
*   - USB CDC On Boot: "Disabled"
*   - Flash Mode: "OPI 80MHz"
*   - Upload Speed: "115200"
*
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define TFT_WIDTH   80
#define TFT_HEIGHT  160

#define TFT_MOSI    11  // SDA
#define TFT_SCLK    12  // SCL
#define TFT_CS      9   // CS
#define TFT_DC      10  // DC
#define TFT_RST     14  // RES
#define TFT_BLK     13  // BLK

//#define ST7735_MADCTL_BGR 0x0 // for RED and BLUE switch

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


void setup() {
  Serial.begin(115200);
  while(!Serial);

  Serial.println(); Serial.println();
  Serial.println("ST7735 Test");
  Serial.println("-----------------------------------------------------");

  tft.initR(INITR_MINI160x80);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  
  Serial.println("Display initialized.");
  Serial.println(ST7735_MADCTL_BGR);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(0,10);
  tft.println("ST7735 Test.");
  
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(1);
  tft.setCursor(0,40);
  tft.println("Color test (GREEN)...");

  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.setCursor(0,55);
  tft.println("Color test (RED)...");

  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(1);
  tft.setCursor(0,70);
  tft.println("Color test (BLUE)...");

}

void loop() {
  // put your main code here, to run repeatedly:

}
