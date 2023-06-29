#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>//Incluimos la librería en el código 
#include <Servo.h>
#include "LedControl.h"
LedControl Qleds = LedControl(12,11,10,1);
Servo servoMotor;
SoftwareSerial bluetooth(2,3);
char nombres[21] = "Ale-06";
char BPS = '4';
char contras[5] =  "1234";
int valor;
int valor2;
char data = 0; //Variable de lectura Bluetooth
int PLED = 4; //Puerto de conexión del LED
int LED2=5;
int led3=6;
int led4=7;
Adafruit_NeoPixel leds= Adafruit_NeoPixel(12,8, NEO_GRB + NEO_KHZ800 );
byte arreglo[8] = {
B00011000,
B00011000,
B00011000,
B11100111,
B11100111,
B00011000,
B00011000,
B00011000};

 

byte arreglo2[8] = {
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000};

byte arreglo3[8] = {
B00011000,
B00011000,
B00011000,
B11111111,
B11111111,
B00011000,
B00011000,
B00011000};

 


void setup() {
leds.begin();
bluetooth.begin(9600);
Serial.begin(9600);

 

Qleds.shutdown(0,false);
Qleds.setIntensity(0,6);// La valores estan entre 1 y 15
Qleds.clearDisplay(0);

 

servoMotor.attach(9);
servoMotor.write(0);
pinMode(13, OUTPUT); //LED placa como salida 
digitalWrite(13, LOW); //LED placa apagado;

 

bluetooth.print("AT");
delay(1000);

 

bluetooth.print("AT+NAME");
bluetooth.print(nombres);
delay(1000);

 

bluetooth.print("AT+BAUD");
bluetooth.print(BPS);
delay(1000);

 

bluetooth.print("AT+PIN");
bluetooth.print(contras);
delay(1000);

 

digitalWrite(13, HIGH); //LED placa encendido
  delay(3000);
  digitalWrite(13, LOW); 
  pinMode (PLED, OUTPUT); //LED como salida 
  pinMode (LED2, OUTPUT); //LED como salida 
  pinMode (led3, OUTPUT); //LED como salida 
  pinMode (led4, OUTPUT); //LED como salida 

}

 

void loop() {
if (Serial.available() > 0) {
data = Serial.read(); //Guarda en la variable “data” el dato recibido por Bluetooth
switch (data){
case 'A': //LED ON    
digitalWrite(PLED, HIGH);
break;
case 'a': //LED OFF   
digitalWrite(PLED, LOW);
break;
case 'B':
digitalWrite(LED2,HIGH);
break;
case 'b':
digitalWrite(LED2,LOW);
break;
case 'C':
digitalWrite(led3,HIGH);
break;
case 'c':
digitalWrite(led3,LOW);
break;
case 'D':
digitalWrite(led4,HIGH);
break;
case 'd':
digitalWrite(led4,LOW);
break;
case 'I':
for(int i=0; i<8; i++){
Qleds.setRow(0, i, arreglo[i]);
delay(1000);}
case'k':
for(int i=0; i<8; i++){
Qleds.setRow(0, i, arreglo2[i]);
delay(1000);}  
case'M':
for(int i=0; i<8; i++){
Qleds.setRow(0, i, arreglo3[i]);
delay(1000);}

 

case 'O':
leds.clear(); 
leds.setPixelColor(0, leds.Color(180, 0, 200));
  leds.show();
  delay(500);
        leds.setPixelColor(1, leds.Color(0, 150, 90));
  leds.show();
  delay(500);
        leds.setPixelColor(2, leds.Color(10, 190, 150));
  leds.show();
  delay(500);
        leds.setPixelColor(3, leds.Color(150, 90, 150));
  leds.show();
  delay(500);
       leds.setPixelColor(4, leds.Color(150, 200, 150));
  leds.show();
  delay(500);
        leds.setPixelColor(5, leds.Color(200, 190, 180));
  leds.show();
  delay(500);
        leds.setPixelColor(6, leds.Color(150, 200, 0));
  leds.show();
  delay(500);
        leds.setPixelColor(7, leds.Color(150, 160, 60));
  leds.show();
  delay(500);
       leds.setPixelColor(8, leds.Color(150, 165, 200));
  leds.show();
  delay(500);
        leds.setPixelColor(9, leds.Color(150, 100, 185));
  leds.show();
  delay(500);
       leds.setPixelColor(10, leds.Color(150, 175, 200));
  leds.show();
  delay(500);
        leds.setPixelColor(11, leds.Color(150, 200, 175));
  leds.show();
  delay(500);
  break;
  }
}
while (bluetooth.available()>0){
data= bluetooth.read();
Serial.println(valor); 
servoMotor.write(valor);
}
while (bluetooth.available()>0){
valor2= bluetooth.read();
Serial.println(valor2); 
digitalWrite(PLED,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(led3,HIGH);
digitalWrite(led4,HIGH);
delay(1000);
digitalWrite(PLED,LOW);
digitalWrite(LED2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
}
}
