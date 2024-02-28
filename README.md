# yaWebSerial
Yet another web serial library for communication with Serial through WiFI.

**The main difference from similar libraries:**
- does not use websockets;
- doesn't use gzip for html page (you can simple edit web interface to your taste);
- stable operation;

**How it looks**
<p align="left">
	<img src="https://github.com/pervu/yaWebSerial/blob/main/webInterface.png" width="600" alt="webInterface"/>
</p>

## yaWebSerial QuickStart
yaWebSerial uses AsyncTCP-1.1.1 and ESPAsyncWebServer-1.2.3, you can find them in the "lib" folder.<br>
Edit "htmlPage.h" if you need.<br>
After ESP32 WiFi connecting, you will see ip address of the web server in the serial monitor.<br>
Enter this IP to your web browser.<br>
Logo picture is converted to Base64, you can encode your own picture here https://www.base64-image.de/. Than add it to "htmlPage.h" file
```cpp
// include header file
#include <yaWebSerial.h>
// Create web server object
AsyncWebServer server(80);
// Create yaWebSerial object
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
```
That is)
