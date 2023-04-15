/*
 * Adapted by 3tawi
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 */

#ifndef SettingWifi_H
#define SettingWifi_H

#include <WiFi.h>
#include <WebServer.h>
#include "index.h"

WebServer server(80);

class SettingWifi {
  private:
  
const char* Apssid = "Esp32-P3";
const char* Appassword = "GPxMatrix";
  
  public:
    
  void Setup() {
  WiFi.softAP(Apssid, Appassword);
  }

};

#endif
