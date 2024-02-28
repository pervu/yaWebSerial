#include <Arduino.h>
#include <yaWebSerial.h>

// Server object
AsyncWebServer server(80);
// Web Serial object
YaWebSerial webserial(&server);

const char* ssid = "ssid"; // Your WiFi SSID
const char* password = "pswd"; // Your WiFi Password

// Callback function
void receiveMsg(String *data)
{
  Serial.printf("Data received: %s\n", *data);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.printf("WiFi Failed!\n");
      return;
  }
  Serial.printf("IP Address: %s\n", WiFi.localIP().toString());

  // Start WiFi Serial
  webserial.begin();
  // Connect callback func for received web messages
  webserial.msgHandler(receiveMsg);
  // Start web-server
  server.begin();
}

void loop() {
    // Send data to web page
    // Use it with .print or .println methods, like with Serial
    webserial.print(millis());
    delay(500);
}
