#include <ArduinoJson.h>
#define TEMPERATURE_VCC 5.0
#define TEMPERATURE_OFFSET -11.3

void setup() {
  Serial.begin(115200);
  
  pinMode(3, INPUT_PULLUP); // nowButton
  pinMode(4, INPUT_PULLUP); // waitButton
  pinMode(5, INPUT_PULLUP); // door
}

void loop() {
  DynamicJsonDocument data(1024);

  bool nowButtonPressed = !digitalRead(3);
  bool waitButtonPressed = !digitalRead(4);
  bool doorIsOpen = digitalRead(5);

  int lightRaw = analogRead(A0);
  int temperatureRaw = analogRead(A1);

  // for LM61CIZ, V_o = (+10mV/@C x T @C) + 600mV 
  float temperatureCelsius = ((((float) temperatureRaw) / 1023.0f * TEMPERATURE_VCC) - 0.6f) / 0.01f;
  temperatureCelsius += TEMPERATURE_OFFSET;

  data.clear();
  data["type"] = "sensor";
  data["light"] = lightRaw;
  data["temperature"] = temperatureRaw;
  data["temperatureCelsius"] = temperatureCelsius;
  data["nowButtonPressed"] = nowButtonPressed;
  data["waitButtonPressed"] = waitButtonPressed;
  data["doorIsOpen"] = doorIsOpen;

  serializeJson(data, Serial);
  Serial.println();
}

