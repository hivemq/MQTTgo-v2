

#ifndef DISPLAYCMD_H
#define DISPLAYCMD_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <list>
#include <logo.h>
#include <SPIFFS.h>


void display_init();
void display_big(const String& text, int fg = TFT_WHITE, int bg = TFT_BLACK);
void display_lines(const std::list<String>& lines, int fg = TFT_WHITE, int bg = TFT_BLACK);
void display_logo();
void display_topic(const String& mqtt_topic, const String& payload);
void display_Incoming_topic(const String& mqtt_in_topic, const String& payload);
void display_config(const String& broker, const String& mqtt_topic, const String& mqtt_sub_topic);

#endif
