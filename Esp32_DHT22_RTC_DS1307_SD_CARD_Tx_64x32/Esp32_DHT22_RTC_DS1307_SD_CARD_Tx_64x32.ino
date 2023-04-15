/*
// - Lien vidéo : https://youtu.be/Jc8MUwJ_0rg
// - Lien vidéo Gerber File & Schema: https://youtu.be/HIsI88rf6HY
//   REQUIRES the following Arduino libraries:
// - DS1307ESP Library: https://github.com/3tawi/DS1307ESPTime
// - DHT Sensor Library: https://github.com/3tawi/esp32DHT
// - SmartMatrix Library: https://github.com/pixelmatix/SmartMatrix
// - FastLED Library: https://github.com/pixelmatix/FastLED
// - FFT Library: http://www.robinscheibler.org/2017/12/12/esp32-fft.html
// Getting Started ESP32 Px Matrix With SmartMatrix:  https://youtu.be/InhCc_-RBb4
*/
#include <WiFi.h>
#include <WebServer.h>
#include <SD.h>
#include "SPIFFS.h"
#include <FastLED.h>
#include "MatrixCommon.h"
#include "index.h"

WebServer server(80);
const char* Apssid = "Esp32-P3";
const char* Appassword = "GPxMatrix";
const uint16_t kMatrixWidth = 64;
const uint16_t kMatrixHeight = 32;
String  Ssid, Pass;
IPAddress ip(192,168,1,31);
IPAddress gateway(192, 168,1,1);
IPAddress gatewayap(192,168,4,1);
IPAddress subnet(255, 255, 255, 0);


#define AoHeader 0xD9
#define CoHeader 0xC9
#define UpHeader 0x9C
#define endHeader 0x36


String gifDirac = "/acgifs";
String gifDir = "/gifs";
String gifDirs = "/gifss"; // play all GIFs in this directory on the SD card
char filePath[256] = { 0 };
File f, root, gifFile;
Stream* mySeriel;

const uint16_t NUM_LEDS = kMatrixWidth * kMatrixHeight;
rgb16 usPalette[255];
rgb16 usPalettec[255];
uint8_t buff[NUM_LEDS];
rgb8 buffc[NUM_LEDS];
rgb8 buffi[NUM_LEDS];
CRGBPalette16 MesgPalette;
                        

#include "Digitalclock.h"
#include "Effects.h"
Effects effects;
#include "GIFPlayer.h"
#include "Drawable.h"
#include "Playlist.h"
#include "AudioP.h"
AudioP audioP;
#include "Patterns.h"
Patterns patterns;


void(* resetFunc) (void) = 0;//declare reset function at address 0
void setDriver(Stream* s) {
  mySeriel = s;
}
void getWifi() {
  if(wifiapok) 
    WiFi.softAPdisconnect(true);
  char user[30], pasw[30];
  int lengthSsid = Ssid.length() + 1;
  int lengthPass = Pass.length() + 1;
  Ssid.toCharArray(user, lengthSsid);
  Pass.toCharArray(pasw, lengthPass);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(user, pasw);
  int xc = 0;
  while (WiFi.status() != WL_CONNECTED && xc < 10) {
    delay(1000);
    xc++;
  }
  if (WiFi.status() == WL_CONNECTED) { 
    textip = "CONNECTED To: ";
    textip += Ssid;
    textip += " IP Address: http://";
    textip += WiFi.localIP().toString().c_str();
    wifiok = true;
    xmsg = 128, msg = 0, textmsg = textip;
    } else { 
    wifiok = false;
    } 
  wifiapok = false;
}

void setup() {
  Serial.begin(1250000);
  setDriver(&Serial);
  delay(5000);
  SPIFFS.begin();
  SD.begin(5);
  effects.readSttWifi();  
  WiFi.mode(WIFI_AP_STA);
  getWifi();
  if (!wifiok) { effects.getAPWifi(); }
  gif.begin(LITTLE_ENDIAN_PIXELS);
  server.on("/", handleRoot);
  server.on("/mymessg", handleMesg);
  server.on("/mydtime", handleMyTime);
  server.on("/localdatime", handlelocaltime);
  server.on("/mytimezon", handlezoneTime);
  server.on("/mySpeed0", handleSpe0);
  server.on("/mySpeed1", handleSpe1);
  server.on("/mySpeed2", handleSpe2);
  server.on("/mySpeed3", handleSpe3);
  server.on("/mode24h", handleMode24h);
  server.on("/readstat", handlestate);
  server.on("/modepre", handleModePre);
  server.on("/modenex", handleModeNex);
  server.on("/modeauto", handleModeAuto);
  server.on("/modepat", handleModeAuCl);
  server.on("/sendate", handlesendate);
  server.on("/readdata", handledata);
  server.on("/readtext", handletxt);
  server.on("/modesave", handleSave);
  server.on("/Mywifi", handleWifi);
  server.on("/restesp", resetFunc);
  server.begin();
  pinMode(AUDIO_PIN, INPUT);
  effects.readSttspeed();
  Readclock();
  effects.prepacard();
  effects.redtemphumi();
  audioP.setAudioPattern(Ca);
  (!ModeAuCl) ? patterns.setPattern(0) : patterns.setPattern(Ci);
}

void loop()
{
  patterns.drawFrame();
  EVERY_N_SECONDS(60){
    effects.redtemphumi();
  }
}

void handleRoot() {
  server.send(200, "text/html", MAIN_page); //Send web page
}
void handleSave() {
   handleRoot();
   effects.SaveStting();
}
void handleMesg() { 
    handleRoot();
    Message = server.arg("Message");
    xmsg = -1, msg = 0, textmsg  = "";
}
void handleMyTime() { 
    handleRoot();
    int hh = server.arg("htmie").toInt();
    int mm = server.arg("mtmie").toInt();
    int ss = server.arg("stmie").toInt();
    int dd = server.arg("ddate").toInt();
    int mo = server.arg("mdate").toInt();
    int yr = server.arg("ydate").toInt();
    rtc.setTime(ss, mm, hh, dd, mo, yr);
    xmsg = -1, msg = 3, textmsg  = "";
    effects.writeTime();
    NewRTCm = 60;
}
void handlelocaltime() { 
    handleRoot();
    rtc.setTime(server.arg("locadt").toInt());
    xmsg = -1, msg = 3, textmsg  = "";
    effects.writeTime();
    NewRTCm = 60;
}
void handlezoneTime() {
    handleRoot();
    Tz = server.arg("locatz").toInt(); 
    configTime(Tz * 3600, 0, "", "");
    xmsg = -1, msg = 3, textmsg  = "";
    NewRTCm = 60;
}
void handleSpe0() {
    handleRoot();
    sp0 = server.arg("Speed0").toInt();
}
void handleSpe1() {
    handleRoot();
    sp1 = server.arg("Speed1").toInt();
}
void handleSpe2() {
    handleRoot();
    sp2 = server.arg("Speed2").toInt();
}
void handleSpe3() {
    handleRoot();
    sp3 = server.arg("Speed3").toInt();
}
void handleMode24h() {
    handleRoot(); 
    Mode24h = !Mode24h;
    xmsg = -1, msg = 3, textmsg  = "";
    NewRTCm = 60;
}
void handleModeAuto() {
    handleRoot();
    ModeAuto = !ModeAuto;
}
void setPatternModeCl() {
  audioP.stop();
  patterns.setPattern(Ci);
}
void setPalette() {
  usPalette[0] = (rgb16)rgb24{0, 0, 0};
  if (Ci != 3) {
    MesgPalette = RainbowColors_p;
    for (int i=1; i<255; i++) {
      CRGB colo = ColorFromPalette(MesgPalette, i, 255, NOBLEND);
      usPalette[i] = (rgb16)rgb24{colo.r, colo.g, colo.b};
    }
    mySeriel->write(UpHeader);
    mySeriel->write((uint8_t *)usPalette, 510);
  } else {
    mySeriel->write(UpHeader);
    mySeriel->write((uint8_t *)usPalette, 2);
  }
}
void setPatternModeAu() {
  start_tick = true;
  root.close();
  patterns.setPattern(0);
  audioP.start();
  setPalette();
}
void handleModeAuCl() {
  handleRoot();
  ModeAuCl = !ModeAuCl;
  (!ModeAuCl) ? setPatternModeAu() : setPatternModeCl();
}
void handleModeNex() { 
  handleRoot();
  (!ModeAuCl) ? ModeAuNex() : ModeClNex();
}
void ModeAuNex() { 
  audioP.move(1);
  Ca = audioP.getCurrentIndex();
}
void ModeClNex() {
  start_tick = true;
  root.close();
  patterns.move(1);
  Ci = patterns.getCurrentIndex();
}
void handleModePre() { 
  handleRoot();
  (!ModeAuCl) ? ModeAuPre() : ModeClPre();
}
void ModeAuPre() { 
  audioP.move(-1);
  Ca = audioP.getCurrentIndex();
}
void ModeClPre() {
  start_tick = true;
  root.close();
  patterns.move(-1);
  Ci = patterns.getCurrentIndex();
}
void handlesendate() { 
    handleRoot();
    datetxt = server.arg("bday");
    datee = "/Temhumi/";
    datee += datetxt;
    datee += ".txt";
}
void sendatetxt() {
    datetxt = rtc.getTime("%F");
    datee = "/Temhumi/";
    datee += datetxt;
    datee += ".txt";
}
void handletxt() {
  if (datetxt == "") { sendatetxt(); }
  File fdate = SD.open(datee);
  if (fdate) {
    size_t sent = server.streamFile(fdate, "text/plain");
  } else {
    server.send(200, "text/plain", "file not fond");
  }
    fdate.close();
}
void handleWifi() { 
  handleRoot(); 
  Ssid = server.arg("usname");
  Pass = server.arg("pssw");
  getWifi();
  if (!wifiok) effects.getAPWifi();
  else effects.Savewifi();
}
void handledata() {
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += datetxt;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}
void handlestate() {
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += NewTemp;
  content += "</analog><analog>";
  content += NewHumi;
  content += "</analog><analog>";
  content += Tz;
  content += "</analog><analog>";
  content += Mode24h;
  content += "</analog><analog>";
  content += sp0;
  content += "</analog><analog>";
  content += sp1;
  content += "</analog><analog>";
  content += sp2;
  content += "</analog><analog>";
  content += sp3;
  content += "</analog><analog>";
  content += ModeAuto;
  content += "</analog><analog>";
  content += ModeAuCl;
  content += "</analog><analog>";
  content += Ci;
  content += "</analog><analog>";
  content += Ca+1;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}
