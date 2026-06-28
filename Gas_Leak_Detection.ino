
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo windowServo;

// Pins
const int gasSensor = A0;
const int buzzer = 8;
const int led = 9;
const int relayLight = 6;
const int relayFan = 7;
const int servoPin = 10;

int threshold = 350;

void setup() {
  pinMode(gasSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(relayLight, OUTPUT);
  pinMode(relayFan, OUTPUT);

  windowServo.attach(servoPin);
  windowServo.write(0);

  lcd.init();
  lcd.backlight();

  // Normal State
  digitalWrite(relayLight, LOW);   // Light ON (Active LOW relay)
  digitalWrite(relayFan, HIGH);    // Fan OFF

  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);

  lcd.setCursor(0,0);
  lcd.print("Gas Detector");
  lcd.setCursor(0,1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  int gasValue = analogRead(gasSensor);

  lcd.setCursor(0,0);
  lcd.print("Gas:");
  lcd.print(gasValue);
  lcd.print("   ");

  if(gasValue > threshold){

    lcd.setCursor(0,1);
    lcd.print("GAS LEAK!!!   ");

    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);

    digitalWrite(relayLight,HIGH); // Light OFF
    digitalWrite(relayFan,LOW);    // Fan ON

    windowServo.write(90);

  }
  else{

    lcd.setCursor(0,1);
    lcd.print("Gas Safe      ");

    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);

    digitalWrite(relayLight,LOW);  // Light ON
    digitalWrite(relayFan,HIGH);   // Fan OFF

    windowServo.write(0);
  }

  delay(500);
}
