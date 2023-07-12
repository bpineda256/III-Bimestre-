#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C y tamaño de la pantalla

const int sensorPin = A0; // Pin analógico al que está conectado el sensor ACS712

void setup() {
  lcd.begin(16, 2);
  lcd.print("Amperimetro");
  lcd.setCursor(0, 1);
  lcd.print("by Arduino");

  delay(2000);
  lcd.clear();
}

void loop() {
  float voltage = 5.0; // Voltaje de referencia (según la alimentación del Arduino)
  float sensitivity = 0.185; // Sensibilidad del sensor ACS712 (ajustar según el modelo utilizado)

  int sensorValue = analogRead(sensorPin); // Lectura del valor analógico del sensor
  float current = (sensorValue - 512) * (voltage / 1024.0) / sensitivity; // Cálculo de la corriente en amperios

  lcd.setCursor(0, 0);
  lcd.print("Corriente: ");
  lcd.print(current);
  lcd.print(" A");

  delay(1000); // Intervalo de actualización de la pantalla
}