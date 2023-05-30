#include <LiquidCrystal_I2C.h>




LiquidCrystal_I2C lcd(0x27, 16, 2);




const int trigPin = 2;

const int echoPin = 3;

const int pausaPin = 7; // Pausa del circuito

const int BotBomPin = 8; // Boton de la bomba

const int BomPin = 9; // Pin de la bomba

const int alarmaPin = 4;




int distancia = 0;

int limite = 10; // Límite del contenedor en porcentaje

bool pausa = false;




void setup() {




  lcd.begin(16,2);

  lcd.backlight();

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(pausaPin, INPUT_PULLUP);

  pinMode(BotBomPin, INPUT_PULLUP);

  pinMode(BomPin, OUTPUT);

  pinMode(alarmaPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(pausaPin), pausarPrograma, FALLING);

  attachInterrupt(digitalPinToInterrupt(BotBomPin), activarBomba, FALLING);

}




void loop() {




  if (!pausa) {




    distancia = medirdistancia();




    // Calcular el porcentaje de agua

    int percentage = map(distancia, 0, limite, 0, 100);

    percentage = constrain(percentage, 0, 100);




    // Mostrar porcentaje en la pantalla LCD

    lcd.clear();

    lcd.setCursor(0, 0);

    lcd.print("Agua: ");

    lcd.print(percentage);

    lcd.print("%");




    if (distancia <= limite) {

      activarAlarma();

    }

  }

}




int medirdistancia() {

  digitalWrite(trigPin, LOW);

  delayMicroseconds(1);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(1);

  digitalWrite(trigPin, LOW);




  long duration = pulseIn(echoPin, HIGH);

  int distance = duration * 0.034 / 2;

  return distance;

}




void activarAlarma() {

  tone(alarmaPin, 1000);

  delay(500);

  noTone(alarmaPin);

  delay(500);

}




void pausarPrograma() {

  pausa = !pausa;

  if (pausa) {

    tone(alarmaPin, 2000, 10000);

  } else {

    noTone(alarmaPin);

  }

}




void activarBomba() {

  digitalWrite(BomPin, HIGH);

  delay(10000);

  digitalWrite(BomPin, LOW);

}

has context menu