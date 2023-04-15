/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 */

#ifndef PatternAnalogeClock_H
#define PatternDigitalClock_H


class PatternAnalogeClock: public Drawable {
private:

public:
    PatternAnalogeClock() {
        name = (char *)"AnalogeClock";
    }
    
void settimeth() {
  for (int i=0; i<NUM_LEDS; i++) {
    CRGB colo = ColorFromPalette(RainbowColors_p, buff[i], 255, NOBLEND);
    buffi[i] = buff[i] ? (rgb8)rgb24{colo.r, colo.g, colo.b} : buffc[i];
  }
  if (millis() - lastTime > 1000) {
    memset(buff, 0x0, NUM_LEDS);
    drawtime(32, 16, 29, 2);
    flasher = !flasher;
    lastTime = millis();
  }
  if (NewRTCm != rtc.getMinute()) {
    flashSe = !flashSe;
    NewRTCm = rtc.getMinute();
  }
  if(ModeAuto) {
    if (millis() - prevTime > sp3*1000) {
      start_tick = true;
      prevTime = millis();
    }
  }
}
void drawHMS(float angle, int x0, int y0, int w, int t, int c0, int c1, int z1) {
      int x[3];
      int y[3];
      float radians = radians(angle);
      x[0] = x0 + w * sin(radians);
      y[0] = y0 + w/t * cos(radians);
      radians = radians(angle+z1);
      x[1] = x0 + 6 * sin(radians);
      y[1] = y0 + 6/t * cos(radians);
      radians = radians(angle-z1);
      x[2] = x0 + 6 * sin(radians);
      y[2] = y0 + 6/t * cos(radians);
      effects.fillTriangle(x0, y0, x[0], y[0], x[1], y[1], c0);
      effects.fillTriangle(x0, y0, x[0], y[0], x[2], y[2], c0);
      effects.drawLine(x[0], y[0], x[1], y[1], c1);
      effects.drawLine(x[0], y[0], x[2], y[2], c1);
}

void drawtime(int cx, int cy, int w, int t) {
      uint8_t second = rtc.getSecond();
      uint8_t minute = rtc.getMinute();
      uint8_t hour = rtc.getHour();
      if (hour > 12) hour -= 12;
      float angle = 180 - (30 * hour) - (minute / 2);
      drawHMS(angle, cx, cy, w-12, t, 20, 40, 25);
      angle = 180 - (6 * minute);
      drawHMS(angle, cx, cy, w-6, t, 100, 140, 20);
      angle =  180 - (second * 6);
      drawHMS(angle, cx, cy, w, t, second*2, second*2+120, 20);
}

void PlayGIF(char *name)
{
  if (gif.open(name, GIFOpenFile, GIFCloseFile, GIFReadFile, GIFSeekFile, GIFDraw8)) {
    while (gif.playFrame(true, NULL))
    { 
      settimeth();
      mySeriel->write(CoHeader);
      mySeriel->write((uint8_t *)buffi, NUM_LEDS);
      mySeriel->write(endHeader);
      server.handleClient(); 
      if (start_tick)
        break;
    }
    start_tick = false;
    gif.close();
  }
} /* ShowGIF() */
    unsigned int drawFrame() {
      root = SD.open(gifDirac);
      if (root) {
        gifFile = root.openNextFile();
        while (gifFile) {
          memset(filePath, 0x0, sizeof(filePath));                
          strcpy(filePath, gifFile.name());
          PlayGIF(filePath);
          gifFile.close();
          gifFile = root.openNextFile();
          }
         root.close();
      } // root
      return 0;
    }
};

#endif
