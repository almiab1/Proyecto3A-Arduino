//--------------------------------------------------------------------------------------------------------------
// EmisoraBTLE.h
// Clase operadora de la EmisoraBTLE
// Equipo 4
// Carlos Tortosa Micó
// 14-10-2019
// CopyRight
//--------------------------------------------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------------------------------------------
#include <bluefruit.h>
//--------------------------------------------------------------------------------------------------------------
// Clase EmisoraBTLE()
//--------------------------------------------------------------------------------------------------------------
class EmisoraBTLE {
  //--------------------------------------------------------------------------------------------------------------
  // Parte Privada
  //--------------------------------------------------------------------------------------------------------------
  private:
    uint8_t beaconUUID[16] = {
      'i', 'P', 'O', 'L', 'L', 'U', 'T', 'I',
      'O', 'N', '-', '0', '0', '0', '0', '1'
    };
  //--------------------------------------------------------------------------------------------------------------
  // Parte Publica
  //--------------------------------------------------------------------------------------------------------------
  public:
    //--------------------------------------------------------------------------------------------------------------
    // constructor EmisoraBTLE()
    //--------------------------------------------------------------------------------------------------------------
    EmisoraBTLE() {

    }//constructor

    //--------------------------------------------------------------------------------------------------------------
    //
    // [int] --> anunciarO3 --> [void]
    //
    //--------------------------------------------------------------------------------------------------------------
    void anunciarO3(uint16_t datoMajor) {

      BLEBeacon nuevoBeacon(beaconUUID, datoMajor, 0, 73); //El valor del minor no es relevante, pongo un 73 por ejemplo
      nuevoBeacon.setManufacturer(0x004c); //  <- Apple id
      Bluefruit.Advertising.setBeacon( nuevoBeacon );

    }

    //--------------------------------------------------------------------------------------------------------------
    //
    //  [void] --> startAdvertising() --> [void]
    //
    //--------------------------------------------------------------------------------------------------------------
    void startAdvertising() {

      Bluefruit.begin();


      //Set el nombre
      Bluefruit.setName("iPollution-00001");
      Bluefruit.ScanResponse.addName();

      
      //Configuraciones del advertising
      Bluefruit.Advertising.stop(); //Paro de anunciar por si acaso

      Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
      Bluefruit.Advertising.addTxPower();
      Bluefruit.Advertising.addName();


     
      //Crear el beacon inicial
      BLEBeacon elBeacon( beaconUUID, 12, 34, 73 );
      elBeacon.setManufacturer( 0x004c ); // apple id
      Bluefruit.Advertising.setBeacon( elBeacon );

      
      //Ultimas configuraciones antes de empezar
      Bluefruit.Advertising.restartOnDisconnect(true);
      Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
      Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
      Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
    } // startAdvertising()

    //--------------------------------------------------------------------------------------------------------------


}; //Clase EmisoraBTLE
