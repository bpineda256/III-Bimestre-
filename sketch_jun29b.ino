#include <LedControl.h> // Libreria de la Matriz Led

 const int gasSensorPin = 2;// Pin del Sensor de Gas 
 const int buzzerPin = 3;// Pin del buzzer
 const int matrixDataPin = 4;// Pin del DIN
 const int matrixClockPin = 5;// Pin de CLK
 const int matrixCsPin = 6;// Pin de Cs

LedControl matrix = LedControl(matrixDataPin, matrixClockPin, matrixCsPin, 1);
volatile bool isAlertActive = false;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(gasSensorPin, INPUT);
  matrix.shutdown(0, false);
  matrix.setIntensity(0, 8);
  matrix.clearDisplay(0);
  
  // Configurar interrupción por software
  attachInterrupt(digitalPinToInterrupt(gasSensorPin), gasInterrupt, CHANGE);
}

void loop() {
  // Realiza aquí otras tareas que desees mientras el sistema esté en funcionamiento
}

void gasInterrupt() {
  if (digitalRead(gasSensorPin) == HIGH) {
    // Sensor detectó humo o gas
    if (!isAlertActive) {
      isAlertActive = true;
      digitalWrite(buzzerPin, HIGH);
      displayAlertAnimation();
      delay(1000);
    }
  } else {
    // Sensor volvió a su estado normal
    isAlertActive = false;
    digitalWrite(buzzerPin, LOW);
    matrix.clearDisplay(0);
  }
}

void displayAlertAnimation() {
  // Define la animación de alerta en la matriz LED
  byte alertAnimation[8] = {
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B01111110,
    B00111100,
    B00011000,
    B00000000
  };
  
  // Muestra la animación en la matriz LED
  for (int i = 0; i < 8; i++) {
    matrix.setRow(0, i, alertAnimation[i]);
  }
}
