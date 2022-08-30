# MQTTGo v2

This repo contains the source code for setting up a demo consisting of two TTgo devices communiucating over a MQTT broker. For demo purposes the public HiveMQ broker/logo is used but this code is not in anyway endorsed nor supported by HiveMQ.

Best, Kamiel.straatman@hiveMQ.com

## Language

The default language is Dutch; users can pick a different language using the
WiFi configuration portal. To change the default setting to English, change
`#define LANGUAGE "nl"` to `#define LANGUAGE "en"`.

## Usage

### Install.

This repo uses [PlatformIO](https://platformio.org/) to build, compiule and upload your firmware

1. Install Platform IO (within VScode)
2. Clone repo to local drive
3. 'cd' to this repo and run `pio run` . (if you encounter 'not available' errors' please recompile once more)
4. Setup Wifi, Broker, Pub and Sub topics amd the payload by connecting a mobile phone to the Wifi SSID that is displayed on the TTG at startup.

### Installeren.

Deze repository gebruikt [PlatformIO](https://platformio.org/) voor installatie.

1. Installeer PlatformIO.
2. Kloon deze repository lokaal.
3. Ga naar de map van deze repository en voer `pio run` uit. Bij errors tweede maal compileren. 
4. Setup Wifi, Broker, Pub and Sub topics en de payload door een mobile telefoon te verbinden met de Wifi SSID die op het display van de TTgo staat.


