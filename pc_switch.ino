#define BLYNK_TEMPLATE_ID "TMPL6SEwTof73"
#define BLYNK_TEMPLATE_NAME "ESP32"
#define BLYNK_AUTH_TOKEN "xvjiSfYanFxZHRacHdLfA9d0ej_nSP5o"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>



// Your Blynk authentication token
char auth[] = BLYNK_AUTH_TOKEN;

// Your Wi-Fi credentials
char ssid[] = "OptimusPrime";
char pass[] = "05061335";

// Define GPIO pin (ESP32's onboard LED is typically on GPIO2)
#define Switch_PIN 4

// Blynk virtual pin handler
BLYNK_WRITE(V0) { // Virtual pin V0
  int pinValue = param.asInt(); // Get value from virtual pin
  digitalWrite(Switch_PIN, pinValue); // Set GPIO2 state
}

void setup() {
  // Initialize serial monitor
  Serial.begin(115200);
  // Configure GPIO2 as output
  pinMode(Switch_PIN, OUTPUT);
  digitalWrite(Switch_PIN, HIGH);
  
  // Connect to Wi-Fi and Blynk
  Blynk.begin(auth, ssid, pass);
  
  // Optional: Wait for connection
  while (Blynk.connect() == false) {
    // Wait until connected
  }
  
  Serial.println("Connected to Blynk!");
}

void loop() {
  Blynk.run(); // Maintain Blynk connection
  Serial.println(digitalRead(4));
}