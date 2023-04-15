/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * Portions of this code are adapted from LedEffects Snake by Robert Atkins: https://bitbucket.org/ratkins/ledeffects/src/26ed3c51912af6fac5f1304629c7b4ab7ac8ca4b/Snake.cpp?at=default
 * Copyright (c) 2013 Robert Atkins
 *
 */

#ifndef PatternAudio_H
#define PatternAudio_H


#include "FFT.h"

  
class PatternAudio : public Drawable {
private:

public:
    
    fft_config_t *real_fft_plan = fft_init(FFT_N, FFT_REAL, FFT_FORWARD, fft_input, fft_output);
    
    PatternAudio() {
        name = (char *)"Audio";
    }

void setdata() {
  for (int k = 0 ; k < FFT_N ; k++)
    real_fft_plan->input[k] = analogRead(AUDIO_PIN);
  fft_execute(real_fft_plan);
}  
void getdata() {
  for (int i = 1 ; i < real_fft_plan->size / 2 ; i++)
  {
    int mag = sqrt(pow(real_fft_plan->output[2*i],2) + pow(real_fft_plan->output[2*i+1],2))/100;
    mag = map(mag, 0, sp2, 0, 63);
    if(mag>31) mag = 31;
    //16 bands, 12kHz top band
      if      (i<=2 )           levels[0]  = (mag > levels[0]) ? mag : (levels[0] - sp0);
      else if (i>2   && i<=3  ) levels[1]  = (mag > levels[1]) ? mag : (levels[1] - sp0);
      else if (i>3   && i<=5  ) levels[2]  = (mag > levels[2]) ? mag : (levels[2] - sp0);
      else if (i>5   && i<=7  ) levels[3]  = (mag > levels[3]) ? mag : (levels[3] - sp0);
      else if (i>7   && i<=9  ) levels[4]  = (mag > levels[4]) ? mag : (levels[4] - sp0);
      else if (i>9   && i<=11 ) levels[5]  = (mag > levels[5]) ? mag : (levels[5] - sp0);
      else if (i>11  && i<=15 ) levels[6]  = (mag > levels[6]) ? mag : (levels[6] - sp0);
      else if (i>15  && i<=20 ) levels[7]  = (mag > levels[7]) ? mag : (levels[7] - sp0);
      else if (i>20  && i<=26 ) levels[8]  = (mag > levels[8]) ? mag : (levels[8] - sp0);
      else if (i>26  && i<=33 ) levels[9]  = (mag > levels[9]) ? mag : (levels[9] - sp0);
      else if (i>33  && i<=41 ) levels[10] = (mag > levels[10]) ? mag : (levels[10] - sp0);
      else if (i>41  && i<=50 ) levels[11] = (mag > levels[11]) ? mag : (levels[11] - sp0);
      else if (i>50  && i<=60) levels[12] = (mag > levels[12]) ? mag : (levels[12] - sp0);
      else if (i>60 && i<=72) levels[13] = (mag > levels[13]) ? mag : (levels[13] - sp0);
      else if (i>72 && i<=106) levels[14] = (mag > levels[14]) ? mag : (levels[14] - sp0);
      else if (i>106          ) levels[15] = (mag > levels[15]) ? mag : (levels[15] - sp0);
      angle = (angle < mag*4) ? mag*4 : angle;
  }
}

void sentbuff() {
  mySeriel->write(AoHeader);
  mySeriel->write((uint8_t *)buff, NUM_LEDS);
  mySeriel->write(endHeader);
  memset(buff, 0x0, NUM_LEDS);
}

  unsigned int drawFrame() {
    server.handleClient();
    if (millis() - lastTime > sp1) {
      setdata();
      getdata();
      audioP.drawFrame();
      sentbuff();
      lastTime = millis();
    }
    if(ModeAuto) {
      if (millis() - prevTime > sp3*1000) {
        audioP.move(1);
        Ca = audioP.getCurrentIndex();
        prevTime = millis();
      }
    }
    return 0;
  }
};

#endif
