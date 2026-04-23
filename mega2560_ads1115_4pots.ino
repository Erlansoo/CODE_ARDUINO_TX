#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

const uint8_t ADS_ADDRESS = 0x49;
const unsigned long READ_INTERVAL_MS = 100;
const unsigned long PRINT_INTERVAL_MS = 200;

int16_t potValues[4] = {0, 0, 0, 0};
unsigned long lastReadMs = 0;
unsigned long lastPrintMs = 0;

void setup() {
  Serial.begin(9600);

  // Espera opcional para placas con USB nativo (en Mega no es obligatorio)
  delay(100);

  if (!ads.begin(ADS_ADDRESS)) {
    Serial.println("Error: no se encontro ADS1115 en la direccion 0x49");
    while (true) {
      // Bloqueo intencional si no hay comunicacion I2C con el ADC
    }
  }

  // Ganancia +/-6.144V (1 bit = 0.1875mV)
  ads.setGain(GAIN_TWOTHIRDS);

  Serial.println("ADS1115 listo en 0x49");
  Serial.println("Leyendo 4 potenciometros (A0-A3)...");

  unsigned long now = millis();
  lastReadMs = now;
  lastPrintMs = now;
}

void loop() {
  unsigned long now = millis();

  // Lectura cada 100 ms sin usar delay (dt con millis)
  if (now - lastReadMs >= READ_INTERVAL_MS) {
    lastReadMs = now;
    potValues[0] = ads.readADC_SingleEnded(0);
    potValues[1] = ads.readADC_SingleEnded(1);
    potValues[2] = ads.readADC_SingleEnded(2);
    potValues[3] = ads.readADC_SingleEnded(3);
  }

  // Impresion cada 200 ms sin bloquear el loop
  if (now - lastPrintMs >= PRINT_INTERVAL_MS) {
    lastPrintMs = now;
    Serial.print("POT0: ");
    Serial.print(potValues[0]);
    Serial.print("\tPOT1: ");
    Serial.print(potValues[1]);
    Serial.print("\tPOT2: ");
    Serial.print(potValues[2]);
    Serial.print("\tPOT3: ");
    Serial.println(potValues[3]);
  }
}
