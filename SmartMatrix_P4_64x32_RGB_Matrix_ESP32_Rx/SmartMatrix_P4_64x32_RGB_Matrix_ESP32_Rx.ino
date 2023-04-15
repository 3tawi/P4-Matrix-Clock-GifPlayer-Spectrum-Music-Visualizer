/*
// - Lien vidéo : https://youtu.be/Jc8MUwJ_0rg
// - Lien vidéo Gerber File & Schema: https://youtu.be/HIsI88rf6HY
//   REQUIRES the following Arduino libraries:
// - SmartMatrix Library: https://github.com/pixelmatix/SmartMatrix
// - FastLED Library: https://github.com/pixelmatix/FastLED
// - Adafruit_GFX Library: https://github.com/adafruit/Adafruit-GFX-Library
// Getting Started ESP32 Px Matrix With SmartMatrix:  https://youtu.be/InhCc_-RBb4
*/

#define USE_ADAFRUIT_GFX_LAYERS
#include <MatrixHardware_ESP32_V0.h>                // This file contains multiple ESP32 hardware configurations, edit the file to define GPIOPINOUT (or add #define GPIOPINOUT with a hardcoded number before this #include)
#include <SmartMatrix.h>
#include <FastLED.h>

#define COLOR_DEPTH 24                  // Choose the color depth used for storing pixels in the layers: 24 or 48 (24 is good for most sketches - If the sketch uses type `rgb24` directly, COLOR_DEPTH must be 24)
const uint16_t kMatrixWidth = 64;       // Set to the width of your display, must be a multiple of 8
const uint16_t kMatrixHeight = 32;      // Set to the height of your display
const uint8_t kRefreshDepth = 36;       // Tradeoff of color quality vs refresh rate, max brightness, and RAM usage.  36 is typically good, drop down to 24 if you need to.  On Teensy, multiples of 3, up to 48: 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48.  On ESP32: 24, 36, 48
const uint8_t kDmaBufferRows = 4;       // known working: 2-4, use 2 to save RAM, more to keep from dropping frames and automatically lowering refresh rate.  (This isn't used on ESP32, leave as default)
const uint8_t kPanelType = SM_PANELTYPE_HUB75_32ROW_MOD16SCAN;   // Choose the configuration that matches your panels.  See more details in MatrixCommonHub75.h and the docs: https://github.com/pixelmatix/SmartMatrix/wiki
const uint32_t kMatrixOptions = (SM_HUB75_OPTIONS_NONE);        // see docs for options: https://github.com/pixelmatix/SmartMatrix/wiki
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);

#define AoHeader 0xD9
#define CoHeader 0xC9
#define UpHeader 0x9C
#define endHeader 0x36 

Stream* mySeriel;
uint32_t lastData = 1000;
const uint16_t NUM_LEDS = kMatrixWidth * kMatrixHeight;
rgb16 usPalette[255];
rgb8 col[kMatrixWidth];
uint8_t buff[kMatrixWidth];
CRGBPalette16 MesgPalette;

void setDriver(Stream* s) {
  mySeriel = s;
}
void setPalette() {
  MesgPalette = RainbowColors_p;
  usPalette[0] = (rgb16)rgb24{0, 0, 0};
  for (int i=1; i<255; i++) {
    CRGB colo = ColorFromPalette(MesgPalette, i, 255, NOBLEND);
    usPalette[i] = (rgb16)rgb24{colo.r, colo.g, colo.b};
  }
}

void Drawframe() {
  if (mySeriel->read() != UpHeader)
       return;
  int xy = 0, y = 0;
  mySeriel->readBytes((uint8_t *)usPalette, 510);
  rgb24 *buffer = backgroundLayer.backBuffer();
  while (y < kMatrixHeight) {
    xy = y * kMatrixWidth;
    mySeriel->readBytes((uint8_t *)buff, kMatrixWidth);
    for (int i=0; i<kMatrixWidth; i++) {
      if (buff[i] != 0xFF)
        buffer[i+xy] = usPalette[buff[i]];
    }
    y++;
  }
  if (mySeriel->read() != endHeader)
       return;
  backgroundLayer.swapBuffers();
}

void DrawClock() {
  if (mySeriel->read() != CoHeader)
       return;
  int xy = 0, y = 0;
  rgb24 *buffer = backgroundLayer.backBuffer();
  while (y < kMatrixHeight) {
    xy = y * kMatrixWidth;
    mySeriel->readBytes((uint8_t *)col, kMatrixWidth);
    for (int i=0; i<kMatrixWidth; i++) {
      if (buff[i] != 0xFF)
        buffer[i+xy] = (rgb24)col[i];
    }
    y++;
  }
  if (mySeriel->read() != endHeader)
       return;
  backgroundLayer.swapBuffers();
}

void DrawAudio() {
  if (mySeriel->read() != AoHeader)
       return;
  int xy, y = 0;
  rgb24 *buffer = backgroundLayer.backBuffer();
  while (y < kMatrixHeight) {
    mySeriel->readBytes((uint8_t *)buff, kMatrixWidth);
    xy = y * kMatrixWidth;
    for (int i=0; i<kMatrixWidth; i++)
      buffer[i+xy] = usPalette[buff[i]];
    y++;
  }
  if (mySeriel->read() != endHeader)
       return;
  backgroundLayer.swapBuffers();
}

void setup() {
  Serial.begin(1250000);
  setDriver(&Serial);
  delay(5000);
  setPalette();
  matrix.addLayer(&backgroundLayer); 
  matrix.begin();
  backgroundLayer.setBrightness(255);
  //backgroundLayer.enableColorCorrection(true);
}

void loop() {
  if (mySeriel->available() > 0) {
    switch (mySeriel->peek()) {
      case AoHeader:
         DrawAudio();
         lastData = millis();
         break;
      case CoHeader:
         DrawClock();
         lastData = millis();
         break;
      case UpHeader:
         Drawframe();
         lastData = millis();
         break;
      default:
         mySeriel->read();
         break;
    }
  }
}
