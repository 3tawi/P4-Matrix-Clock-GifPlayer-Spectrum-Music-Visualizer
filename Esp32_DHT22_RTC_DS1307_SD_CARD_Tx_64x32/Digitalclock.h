/*
 * Adapted by 3tawi
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef Digitalclock_H
#define Digitalclock_H

#include <DS1307ESPTime.h>
#include <esp32DHT.h>
#include "GPFont.h"

DS1307ESPTime rtc;
DHT22 sensor;


String Message = "Great Projects wish you a very nice day.";
String textmsg, textip;
String datetxt, datee;
float oldTemp, oldHumi;
float NewTemp, NewHumi;
long lastTime, prevTime;
bool flasher = false;
bool flashSe = false;
bool Mode24h = false;
int NewRTCm = 60, msg, xmsg;
int co0, co1, Tz = 1, sp0 = 2, sp1 = 3, sp2 = 350, sp3 = 10;
bool wifiok = false;
bool wifiapok = false;
bool ModeAuto = true;
bool ModeAuCl = false;
bool start_tick = false;
int Ci, Ca;


#define FFT_N 512
#define AUDIO_PIN 34 
#define bandCount   16  
float fft_input[FFT_N];
float fft_output[FFT_N];
int levels[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
float angle = 0;

void Readclock() {
  sensor.setup(13);  // pin 13 is DATA
  sensor.onData([](float humidity, float temperature) {
  NewHumi = humidity;
  NewTemp = temperature;
  }); 
  rtc.DSbegin();
  rtc.DSgetdatime();
  configTime(Tz * 3600, 0, "", "");
}


#endif
