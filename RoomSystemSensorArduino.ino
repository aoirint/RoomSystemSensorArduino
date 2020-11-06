#include <ArduinoJson.h>

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

  data.clear();
  data["type"] = "sensor";
  data["light"] = lightRaw;
  data["temperature"] = temperatureRaw;
  data["nowButtonPressed"] = nowButtonPressed;
  data["waitButtonPressed"] = waitButtonPressed;
  data["doorIsOpen"] = doorIsOpen;

  serializeJson(data, Serial);
  Serial.println();
}

