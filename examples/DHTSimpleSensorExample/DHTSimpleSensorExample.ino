
#include <SimpleSensors.h>
#include <DHT.h>
#include "DHTSimpleSensor.h"

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

DHTTemperatureSensor dht_temp("dht_temp", "DHT Temperature", dht);
DHTHumiditySensor dht_humidity("dht_humidity", "DHT Humidity", dht);

SensorCollection sensors("example", "Test Arduino");

JsonSensorStreamer streamer;

void setup() {

  sensors.addSensor(dht_temp);
  sensors.addSensor(dht_humidity);
  sensors.setup();

  Serial.begin(9600);
}

void loop() {

  streamer.streamSensors(Serial, sensors);
  delay(60000);
}