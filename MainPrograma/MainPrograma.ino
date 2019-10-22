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

// Se crea un objeto SensorO3
SensorO3 miSensor(15, 17);
// Se crea una emisoraBle
EmisoraBTLE miEmisora(String("LaEmisoraDelCarlos"));

//--------------------------------------------------------------------------------------------------------------
void setup() {

  Serial.begin(9600);
  while (!Serial) {};
  miEmisora.startAdvertising();

} // setup()
//--------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------
void loop() {

  medirYPublicar();
  delay(6000);

} // loop()
//--------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------
// 
// [void] -> medirYPublicar() --> [void]
//  
//--------------------------------------------------------------------------------------------------------------
void medirYPublicar() {

  uint16_t dato = miSensor.medirO3(); //El dato no es real, es decidido entre el 1 y el 1000 aleatoriamente
  Serial.print("Estoy enviando el numero: ");
  Serial.println(dato);
  miEmisora.anunciarO3(dato);
  
} // medirYPublicar()

//--------------------------------------------------------------------------------------------------------------