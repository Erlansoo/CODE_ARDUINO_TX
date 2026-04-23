#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

const uint8_t ADS_ADDRESS = 0x49;
const unsigned long READ_INTERVAL_MS = 200;

void setup() {
  Serial.begin(9600);

  // Espera opcional para placas con USB nativo (en Mega no es obligatorio)
  delay(100);

  if (!ads.begin(ADS_ADDRESS)) {
    Serial.println("Error: no se encontro ADS1115 en la direccion 0x49");
    while (true) {
      delay(1000);
    }
  }

  // Ganancia +/-6.144V (1 bit = 0.1875mV)
  ads.setGain(GAIN_TWOTHIRDS);

  Serial.println("ADS1115 listo en 0x49");
  Serial.println("Leyendo 4 potenciometros (A0-A3)...");
}

void loop() {
  int16_t pot0 = ads.readADC_SingleEnded(0);
  int16_t pot1 = ads.readADC_SingleEnded(1);
  int16_t pot2 = ads.readADC_SingleEnded(2);
  int16_t pot3 = ads.readADC_SingleEnded(3);

  Serial.print("POT0: ");
  Serial.print(pot0);
  Serial.print("\tPOT1: ");
  Serial.print(pot1);
  Serial.print("\tPOT2: ");
  Serial.print(pot2);
  Serial.print("\tPOT3: ");
  Serial.println(pot3);

  delay(READ_INTERVAL_MS);
}
