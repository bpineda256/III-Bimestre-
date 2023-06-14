#include <Stepper.h>
#include "LedControl.h"
LedControl leds = LedControl(11,13,10,1);
#define boton1 7
#define boton2 6
#define boton3 5
int estado1;
int estado2;
int estado3;
const int pasos_T=2048;
Stepper motor(pasos_T,8,4,9,3);
byte arreglo[8] = {
B00011000,
B01111000,
B00011000,
B00011000,
B00011000,
B00011000,
B00111100,
B00000000};
byte arreglo2[8] = {
B00000000,
B01111000,
B01001000,
B00011000,
B00010000,
B00100000,
B01111100,
B00000000};
byte arreglo3[8] = {
B00000000,
B01111000,
B00000100,
B01111100,
B00000100,
B01111100,
B00000000,
B00000000};

#define OutPin(boton1) pinMode(boton1,INPUT)
#define OutPin(boton2) pinMode(boton2, INPUT)
#define OutPin(boton3) pinMode(boton3, INPUT)
void setup() {
  motor.setSpeed(15);
 OutPin(boton1);
 OutPin(boton2); 
 OutPin(boton3);
 leds.shutdown(0,false);
  leds.setIntensity(0,6);// La valores estan entre 1 y 15 
  leds.clearDisplay(0);
}

void loop() {


  estado1= digitalRead(boton1);
estado2 = digitalRead(boton2);
estado3 = digitalRead(boton3);

  if(estado1==0){
  motor.step(1000);
for(int i=0; i<8; i++)
{
  leds.setRow(0, i, arreglo2[i]); 
}  
  delay(1000);
  }
  
   if(estado2==0){
  motor.step(1500);
   for(int i=0; i<8; i++)
{
  leds.setRow(0, i, arreglo3[i]); 
}
  delay(1000);
  }

  
  
   if(estado3==0){
  motor.step(-2000);
  for(int i=0; i<8; i++)
{
  leds.setRow(0, i, arreglo[i]); 
}
  delay(1000);
  }
}

