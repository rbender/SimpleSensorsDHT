#include "Arduino.h"
#include "SimpleSensors.h"
#include "DHT.h"

#ifndef DHTTemperatureSensor_h
#define DHTTemperatureSensor_h

class DHTTemperatureSensor : public SimpleSensor {

  public:
    DHTTemperatureSensor(char* id, char* name, DHT& dht);    
    void setup();
    
    boolean hasRaw() const;
    
    float read();
    int readRaw();
  
  private:
    DHT* _dht;
};

class DHTHumiditySensor : public SimpleSensor {

  public:
    DHTHumiditySensor(char* id, char* name, DHT& dht);    
    void setup();
    
    boolean hasRaw() const;
    
    float read();
    int readRaw();
  
  private:
    DHT* _dht;
};

#endif
