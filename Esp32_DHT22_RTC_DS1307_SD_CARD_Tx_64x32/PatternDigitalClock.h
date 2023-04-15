/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * Portions of this code are adapted from LedEffects Snake by Robert Atkins: https://bitbucket.org/ratkins/ledeffects/src/26ed3c51912af6fac5f1304629c7b4ab7ac8ca4b/Snake.cpp?at=default
 * Copyright (c) 2013 Robert Atkins
 *
 */

#ifndef PatternDigitalClock_H
#define PatternDigitalClock_H


class PatternDigitalClock : public Drawable {
private:

public:
    PatternDigitalClock() {
        name = (char *)"DigitalClock";
    }

void getmesg() {
  xmsg = 64;
  co0 = random(128, 255);
  switch(msg) {
    case 0 :
        textmsg = Message;
        msg++;
        break;
    case 1 :
        textmsg  = "T:";
        textmsg += NewTemp;
        textmsg += (char)127;
        msg++;
        break;
    case 2 :
        textmsg  = "H:";
        textmsg += NewHumi;
        textmsg += "%";
        msg++;
        break;
    case 3 :
        textmsg  = rtc.getAmPm();
        textmsg += " ";
        textmsg += rtc.getDate(true);
        msg = 0;
        break;
    }
}  
void drawHMSTime() {
  String text = Mode24h ? rtc.getTime("%H") : rtc.getTime("%I");
  effects.setFont(NuFont);
  effects.setCursor(-2, 13);
  effects.print(text);
  text = rtc.getTime("%M");
  effects.setCursor(34, 13);
  effects.print(text);
  text = flasher ? "" : ":";
  effects.setCursor(26, 12);
  effects.print(text);
  int xx = rtc.getSecond();
  xx = flashSe ? xx+2 : 61-xx;
  effects.fillEllipse(xx, 10, 2, 1, xx*2+1);
    }


void drawMesg() {
  int text_length = -(textmsg.length() * 8);
  effects.setFont(GPFont8x8); 
  effects.setCursor(xmsg, 1);
  effects.print(textmsg);
  xmsg -= sp0;
  if (xmsg < text_length) {
    getmesg();
  }
}
void settimeth() {
  effects.FillNoise();
  memset(buff, 0x0, NUM_LEDS);
  drawMesg();
  drawHMSTime();
  for (int i=0; i<NUM_LEDS; i++) {
    CRGB colo = ColorFromPalette(MesgPalette, buff[i], 255, NOBLEND);
    buffi[i] = buff[i] ? (rgb8)rgb24{colo.r, colo.g, colo.b} : buffc[i];
  }
  if (millis() - lastTime > 1000) {
    flasher = !flasher;
    lastTime = millis();
  }
  if (NewRTCm != rtc.getMinute()) {
    effects.NoiseVariablesSetup();
    effects.RandomPalette();
    flashSe = !flashSe;
    NewRTCm = rtc.getMinute();
  }
  if(ModeAuto) {
    if (millis() - prevTime > sp3*1000) {
      start_tick = true;
      prevTime = millis();
    }
  }
  noise_x += 800;
  noise_y += 800;
  noise_z += 800;
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
      root = SD.open(gifDirs);
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
