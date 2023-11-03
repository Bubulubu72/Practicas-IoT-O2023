#include <DHT.h>
#include <DHT_U.h>
// DHT sensor library - Version: Latest
#include <DHT.h>
#include <DHT_U.h>
#define pin1 15 //ESPECIFICAR PIN
DHT dht1(pin1, DHT11); //INICIALIZAR DHT
#define PIN_LED 12 //ESPECIFICAR PIN LED
/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled 2"
  https://create.arduino.cc/cloud/things/ab6cd62a-0a28-4f52-8245-3a6795797eb1
  Arduino IoT Cloud Variables description
  The following variables are automatically generated and updated when changes are made to the Thing
  CloudLight luz;
  CloudTemperatureSensor temperatura;
  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
#include "thingProperties.h"
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  // Defined in thingProperties.h
  initProperties();
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(PIN_LED,OUTPUT); //DEFINIR LED COMO OUTPUT
  dht1.begin(); //INICIAR DHT
}
void loop() {
  ArduinoCloud.update();
  // Your code here
  //ASIGNAR LA LECTURA a la variable declarada
temperatura = dht1.readTemperature();
//IMPRIMIR EN EL MONITOR SERIAL LA TEMPERATURA
Serial.println(temperatura);
delay(4000);
}
/*
  Since Temperatura is READ_WRITE variable, onTemperaturaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperaturaChange()  {
  // Add your code here to act upon Temperatura change
}
/*
  Since Luz is READ_WRITE variable, onLuzChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLuzChange()  {
  // Add your code here to act upon Luz change
  //ASIGNAR EL ESTADO DEL LED A TU VARIABLE LUZ
digitalWrite(PIN_LED, luz);
}
