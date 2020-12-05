
//--------------------------------------------------------------------------------------------------------------
// MainPrograma.ino
// Programa que controla el sparkfunk
// Equipo 4
// Carlos Tortosa
// 14-10-2019
// CopyRight
//--------------------------------------------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------------------------------------------
#include "SensorO3.h";

#include "EmisoraBTLE.h";

// #include <ArduinoLowPower.h>

// #include <LowPower.h>

// Se crea un objeto SensorO3
SensorO3 miSensor(15, 17);
// Se crea una emisoraBle
EmisoraBTLE miEmisora;
// contador del tiempo que lleva el nRF
int contadorTiempo = 0;

//--------------------------------------------------------------------------------------------------------------
void setup() {
  Serial1.begin(9600);
  while (!Serial1) {};
  miEmisora.startAdvertising();

} // setup()
//--------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------
void loop() {

  medirYPublicar();
 //  LowPower.sleep(5000);
 
 // Enter power down state for 8 s with ADC and BOD module disabled
 //  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  

} // loop()
//--------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------
// 
// [void] -> medirYPublicar() --> [void]
//  
//--------------------------------------------------------------------------------------------------------------
void medirYPublicar() {

  int medidaO3 = miSensor.medirO3();
  int temperatura = miSensor.medirTemperatura();
  int humedad = miSensor.medirHumedad();
  
  miEmisora.anunciarO3(medidaO3,temperatura, humedad);
  
  
} // medirYPublicar()

//void dummy() {
  // Función llamada cuando despierta el nRF
  //contadorTiempo += 5;
//}

//--------------------------------------------------------------------------------------------------------------
