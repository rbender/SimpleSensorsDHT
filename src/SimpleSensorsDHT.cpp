#include "Arduino.h"
#include "SimpleSensors.h"
#include "DHTSimpleSensor.h"

DHTTemperatureSensor::DHTTemperatureSensor(char* id, char* name, DHT& dht) : SimpleSensor(id, name, "temperature", "f") {
  _dht = &dht;
}

void DHTTemperatureSensor::setup() {
  //Nothing to do
}

boolean DHTTemperatureSensor::hasRaw() const {
  return false;
}

int DHTTemperatureSensor::readRaw() {
  return -1;
}

float DHTTemperatureSensor::read() {
  return _dht->readTemperature(true);
}

//--------------------------------------------------

DHTHumiditySensor::DHTHumiditySensor(char* id, char* name, DHT& dht) : SimpleSensor(id, name, "humidity", "%") {
  _dht = &dht;
}

void DHTHumiditySensor::setup() {
  //Nothing to do
}

boolean DHTHumiditySensor::hasRaw() const {
  return false;
}

int DHTHumiditySensor::readRaw() {
  return -1;
}

float DHTHumiditySensor::read() {
  return _dht->readHumidity();
}
