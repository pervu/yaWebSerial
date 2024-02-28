#include "yaWebSerial.h"

YaWebSerial::YaWebSerial(AsyncWebServer *server)
{
    _server = server;
    _events = new AsyncEventSource("/events");
    _isEcho = false;
}

void YaWebSerial::begin()
{
    // Set routs for the web server
    _server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", htmlPage);
    });

    _server->on("/send", HTTP_POST, [this](AsyncWebServerRequest *request){
        if (request->params() == 0) {
            request->send(400, "text/plain", "No command provided");
            return;
        }
        
        for (size_t i = 0; i < request->params(); i++) {
        AsyncWebParameter* param = request->getParam(i);
        if (param->name() == "command") {
            String data = param->value();
            if(_receiveFunc != NULL)
            {
                _receiveFunc(&data);
            }
            // Send answer to client
            if (!data.isEmpty())
            {
            if (_isEcho)
            {
                String str = "[" + static_cast<String>(millis()) + "] Echo: " + data + "\n";
                request->send(200, "text/plain", str);
            }
            }
            else
            {
                request->send(400, "text/plain", "No command provided");
            }
        }
        if (param->name() == "checkbox")
        {
            String echoStatus;
            if (param->value() == "1") 
            {
                echoStatus = "ON";
                _isEcho = true;
            }
            else 
            {
                echoStatus = "OFF";
                _isEcho = false;
            }
            request->send(200, "text/plain", "Echo: " + echoStatus + "\n");
        }
        }
    });

    // Connect event to URL "/events"
    _server->addHandler(_events);
}


void YaWebSerial::msgHandler(CallbackFunction _rcvCb)
{
    _receiveFunc = _rcvCb;
}

size_t YaWebSerial::write(uint8_t)
{
    return(1);
}

size_t YaWebSerial::write(const uint8_t *buffer, size_t)
{
    _events->send((const char *)buffer, "message");
    return(1);
}
