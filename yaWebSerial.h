//***************************************************
//* Yet another web serial library                             *
//* for communication with Serial through WiFI      *
//* For ESP32, ESP8266                              *
//* Copyright (C) 2024 Pavel Pervushkin.            *
//* Released under the MIT license.                 *
//***************************************************

#ifndef yaWebSerial_h
#define yaWebSerial_h

#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <htmlPage.h>

class YaWebSerial : public Print {

private:
    AsyncWebServer *_server;
    AsyncEventSource *_events;
    bool _isEcho;
    
protected:
    typedef std::function<void(String *datastr)> CallbackFunction;
    CallbackFunction _receiveFunc = NULL;

public:
    YaWebSerial(AsyncWebServer *server);
    ~YaWebSerial(){}
    void begin();
    void msgHandler(CallbackFunction _rcvCb);

    // Print overload func
    size_t write(uint8_t);
    size_t write(const uint8_t* buffer, size_t size); 
};

#endif