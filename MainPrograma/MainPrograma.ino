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
EmisoraBTLE miEmisora();

//--------------------------------------------------------------------------------------------------------------
void setup() {

  Serial.begin(9600);
  while(!Serial){};
  Serial1.begin(9600);
  while (!Serial1) {};
  //miEmisora.startAdvertising();

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

  int medidaO3 = miSensor.medirO3();
  int temperatura = miSensor.medirTemperatura();
  int humedad = miSensor.medirHumedad();

  //Muestra por monitor Serie
  Serial.print("Medida 03: "); Serial.println(medidaO3);
  Serial.print("Medida Temperatura: "); Serial.println(temperatura);
  Serial.print("Medida Humedad: "); Serial.println(humedad);
  
  //miEmisora.anunciarO3(dato);
  
} // medirYPublicar()

//--------------------------------------------------------------------------------------------------------------
