#include <SPI.h>       //Librerias que se utilizaran 
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //definir pin del led verde
#define LED_R 5 //definir pin del led rojo
#define BUZZER 2 //definir pin del buzzer
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Crear MFRC522
Servo myServo; //definir nombre del servomotor

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup() 
{
  Serial.begin(9600);   // Inicializar comunicación serial
  SPI.begin();      // Inicializar SPI-Bus
  mfrc522.PCD_Init();   // Inicializar MFRC522
  myServo.attach(3); //pin del servomotor
  myServo.write(0); //posicion inicial del servomotor
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  
  lcd.begin(16, 2); // Inicializar el LCD
  lcd.backlight(); // Activar el backlight
  
  lcd.setCursor(0, 0);
  lcd.print("ACCESO:");
}

void loop() 
{
  // Ver por nuevas cards
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // seleccionar una de las cards
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostrar UID en el monitor Serial
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  lcd.setCursor(0, 1); // Mover cursor a la segunda linea
  if (content.substring(1) == "C9 87 88 D3" || content.substring(1) == "" || content.substring(1) == "B2 54 9E 1C" || content.substring(1) == "2D 66 DE 5F") //los acessos que tendra
  {
    lcd.print("ACCESO PERMITIDO");
    Serial.println("Acceso autorizado");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 200,900);
    delay(100);
    noTone(BUZZER);
    myServo.write(360);
    delay(2500);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESO:");
  }
  else
  {
    lcd.print("ACCESO ERRONEO");
    Serial.println(" Acceso denegado");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESO:");
  }
}
