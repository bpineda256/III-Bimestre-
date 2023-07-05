// agregamos librerias
#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <Servo.h>

Servo servo_horizontal;
Servo servo_vertical;
ADXL345 adxl;             //Declaramos nuestro acelerometro ADXL345

//Declaramos variables 
int mappedRawX, mappedejeY;

void setup() { // inicializamos nuestro programa
  inicializar();
  configurarServos();
  esperarInicializacion();
}

void loop() { //lee y espera a los a servos
  leerAcelerometro();
  actualizarServos();
  esperar(100);
}

void inicializar() {  // iniciamos el  programa principal
  Serial.begin(9600);
  adxl.powerOn();
  adxl.setRangeSetting(2);
}

void configurarServos() {
  servo_horizontal.attach(3);
  servo_vertical.attach(5);
  servo_horizontal.write(90);
  servo_vertical.write(90);
}

void esperarInicializacion() { // bucle de tiempo para esperar a los servos 
  delay(2000);
}

void leerAcelerometro() {
  int ejeX, ejeY, ejeZ;
  adxl.readAccel(&ejeX, &ejeY, &ejeZ);
  mappedRawX = map(ejeX, -255, 255, 179, 0);
  mappedejeY = map(ejeY, -255, 255, 0, 179);
}

void actualizarServos() {
  servo_horizontal.write(mappedRawX);
  servo_vertical.write(mappedejeY);
}

void esperar(int ms) {  //Esta función generaliza la espera durante un período de tiempo específico en milisegundos.
  delay(ms);
}