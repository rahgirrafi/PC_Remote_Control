#define BLYNK_TEMPLATE_ID "TMPL6SEwTof73"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "xvjiSfYanFxZHRacHdLfA9d0ej_nSP5o"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;

// Your Wi-Fi credentials
char ssid[] = "OptimusPrime";
char pass[] = "05061335";

#define Switch_PIN 4

BLYNK_WRITE(V0) { // Virtual pin V0
  int pinValue = param.asInt(); // Get value from virtual pin
  digitalWrite(Switch_PIN, pinValue); // Set GPIO2 state
}

void setup() {
  Serial.begin(115200);
  pinMode(Switch_PIN, OUTPUT);
  digitalWrite(Switch_PIN, HIGH);
  Blynk.begin(auth, ssid, pass);

  if (Blynk.connected()) {
    Serial.println("Connected to Blynk!");
  } else {
    Serial.println("Blynk connection failed, but continuing...");
  }
}

void loop() {
  Blynk.run(); // Maintain Blynk connection
  Serial.println(digitalRead(4));
}
