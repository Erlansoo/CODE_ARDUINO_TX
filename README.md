# CODE_ARDUINO_TX

Sketch para **Arduino Mega 2560** que lee 4 potenciómetros usando un **ADS1115** en dirección **0x49** e imprime los valores por Serial a **9600 bps**.

## Archivo principal
- `mega2560_ads1115_4pots.ino`

## Requisitos
- Librería: `Adafruit ADS1X15`
- Conexión I2C en Mega 2560:
  - `SDA` -> pin 20
  - `SCL` -> pin 21

## Comportamiento
- Inicializa Serial a 9600.
- Inicia ADS1115 en dirección 0x49.
- Lee canales `A0`, `A1`, `A2`, `A3` del ADS1115.
- Imprime continuamente:
  - `POT0`, `POT1`, `POT2`, `POT3`
