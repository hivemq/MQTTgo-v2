#include "display-cmd.h"

TFT_eSPI        display;
TFT_eSprite     sprite(&display);

const int       pin_backlight    = 4;

void display_big(const String& text, int fg , int bg ) {
    sprite.fillSprite(TFT_BLACK);
    sprite.setTextSize(1);
    bool nondigits = false;
    for (int i = 0; i < text.length(); i++) {
        char c = text.charAt(i);
        if (c < '0' || c > '9') nondigits = true;
    }
    sprite.setTextFont(nondigits ? 4 : 8);
    sprite.setTextSize(nondigits && text.length() < 10 ? 2 : 1);
    sprite.setTextDatum(MC_DATUM);
    sprite.setTextColor(fg, bg);
    sprite.drawString(text, display.width()/2, display.height()/2);
    sprite.pushSprite(0, 0);
}

void display_lines(const std::list<String>& lines, int fg , int bg ) {
    sprite.fillSprite(TFT_BLACK);
    sprite.setTextSize(1);
    sprite.setTextFont(4);
    sprite.setTextDatum(MC_DATUM);
    sprite.setTextColor(fg, bg);

    const int line_height = 32;
    int y = display.height()/2 - (lines.size()-1) * line_height/2;
    for (auto line : lines) {
        sprite.drawString(line, display.width()/2, y);
        y += line_height;
    }
    sprite.pushSprite(0, 0);
}

void display_init() {
    pinMode(pin_backlight, OUTPUT);
    digitalWrite(pin_backlight, HIGH);
    display.init();
    display.fillScreen(TFT_BLACK);
    display.setRotation(1);
    sprite.createSprite(display.width(), display.height());
   
}

void display_logo() {
    sprite.fillSprite(TFT_BLACK);
    sprite.setSwapBytes(true);
    sprite.pushImage(12, 30, 215, 76, COMP_LOGO);
    sprite.pushSprite(0, 0);
}


void display_topic(const String& mqtt_topic, const String& payload)
{
    display.fillScreen(TFT_BLACK);
    display.setCursor(0, 0, 2);
    
    display.setTextColor(TFT_CYAN,TFT_BLACK);    
    display.setTextFont(4);
    display.println("Last Pub'ed:"); 
    


    display.setTextColor(TFT_GREEN,TFT_BLACK);    
    display.setTextFont(2);
    display.println("on Topic:"); 
    
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(mqtt_topic); 
    
    display.setTextColor(TFT_GREEN,TFT_BLACK);    display.setTextFont(2);
    display.println("Payload:"); 
    
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(payload); 
}   

void display_Incoming_topic(const String& mqtt_in_topic, const String& payload)
{
    display.fillScreen(TFT_BLACK);
    display.setCursor(0, 0, 2);

    display.setTextColor(TFT_CYAN,TFT_BLACK);    
    display.setTextFont(4);
    display.println("Last incomming :"); 
        
    display.setTextColor(TFT_DARKGREEN,TFT_BLACK);    display.setTextFont(2);
    display.println("on Topic:"); 
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(mqtt_in_topic); 
    
    display.setTextColor(TFT_WHITE,TFT_BLACK);    display.setTextFont(2);
    display.println("withPayload:"); 
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(payload); 
}

void display_config(const String& broker, const String& mqtt_topic, const String& mqtt_sub_topic){
    display.fillScreen(TFT_BLACK);
    display.setCursor(0, 0, 2);

    display.setTextColor(TFT_GREEN,TFT_BLACK);    display.setTextFont(2);
    display.println("Broker :"); 
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(broker); 

    display.setTextColor(TFT_GREEN,TFT_BLACK);    display.setTextFont(2);
    display.println("Publishing on Topic:"); 
    
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(mqtt_topic); 
    
    display.setTextColor(TFT_GREEN,TFT_BLACK);    display.setTextFont(2);
    display.println("Subscribing to Topic:"); 
    
    display.setTextColor(TFT_RED,TFT_BLACK);    display.setTextFont(4);
    display.println(mqtt_sub_topic); 
}