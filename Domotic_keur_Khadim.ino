#include <Servo.h>
int photoresistance = A0;
//variable pin
int PirInt = 51;
int PirExt = 53;
int buttonPinV = 44;
int buttonPinB = 50;
int buttonPinJ = 42;
int buttonPinR = 52;
int buttonPinAct = 48;
int buttonPinDes = 46;
int ledChV = 26;
int ledChB = 24;
int ledChJ = 22;
int ledChR = 28;
int ledExt = 30;
int ledAct = 13;
int ledAlert = 12;
int buzzerPin = 23;
int pin_servo = 11;
//initialisation
int photocellReading;
int varPir;
int etatButtonV = 0;
int etatButtonB = 0;
int etatButtonJ = 0;
int etatButtonR = 0;
int etatButtonAct = 0;
int etatButtonDes = 0;
int var_servo = 0;
int pos = 0;
Servo myservo;
void setup() {
  Serial.begin(9600);
  
pinMode(ledChV, OUTPUT);
pinMode(ledChB, OUTPUT);
pinMode(ledChJ, OUTPUT);
pinMode(ledChR, OUTPUT);
pinMode(ledExt, OUTPUT);
pinMode(ledAct, OUTPUT);
pinMode(ledAlert, OUTPUT);
pinMode(buttonPinV, INPUT);
pinMode(buttonPinB, INPUT);
pinMode(buttonPinJ, INPUT);
pinMode(buttonPinR, INPUT);
pinMode(buttonPinAct, INPUT);
pinMode(buttonPinDes, INPUT);
pinMode(buzzerPin,OUTPUT); 
pinMode(PirInt, INPUT);
pinMode(PirExt, INPUT);
myservo.attach(pin_servo);
  // put your setup code here, to run once:

}

void loop() {
  //lecture variable
  int varButtonV = digitalRead(buttonPinV);
  int varButtonB = digitalRead(buttonPinB);
  int varButtonJ = digitalRead(buttonPinJ);
  int varButtonR = digitalRead(buttonPinR);
  int varButtonPinAct = digitalRead(buttonPinAct);
  int varButtonPinDes = digitalRead(buttonPinDes);
  delay(200);
  photocellReading = analogRead(photoresistance);
  varPir = digitalRead(PirInt);
  /////////////Systeme eclairage automatique////////////
  if (photocellReading < 300){
     digitalWrite(ledExt, HIGH);
  }
  else{
    digitalWrite(ledExt, LOW);
  }
  //////////////////////////////////////////////
  ////////////////Systeme alerte//////////////
  if (varButtonPinAct == true){
    etatButtonAct++;
    Serial.println(etatButtonAct);
  }
  if (etatButtonAct == 1){
    digitalWrite(ledAct, HIGH);
    if(varPir == true){
      digitalWrite(buzzerPin, HIGH);
      //digitalWrite(ledAlert, HIGH);
    }
  }
  else if (etatButtonAct == 2){
    digitalWrite(ledAct, LOW);
    etatButtonAct = 0; 
  }
  if( varButtonPinDes == true){
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledAlert, LOW);
  }
  ///////////////////////////////////////////////////////
  //////////////lampe Salon vert////////////////////////
  if(varButtonV == true){
    etatButtonV++;
    Serial.println(etatButtonV);
  }
  if(etatButtonV == 1){
    digitalWrite(ledChV, HIGH);
  }
  else if (etatButtonV == 2){
    digitalWrite(ledChV, LOW);
    etatButtonV = 0;
  }
  ///////////////////////////////////////////////////////
  //////////////lampe Salon Bleu////////////////////////
   if(varButtonB == true){
    etatButtonB++;
  }
  if(etatButtonB == 1){
    digitalWrite(ledChB, HIGH);
  }
  else if (etatButtonB == 2){
    digitalWrite(ledChB, LOW);
    etatButtonB = 0;
  }
    ///////////////////////////////////////////////////////
  //////////////lampe Salon jaune////////////////////////
   if(varButtonJ == true){
    etatButtonJ++;
  }
  if(etatButtonJ == 1){
    digitalWrite(ledChJ, HIGH);
  }
  else if (etatButtonJ == 2){
    digitalWrite(ledChJ, LOW);
    etatButtonJ = 0;
  }
  ///////////////////////////////////////////////////////
  //////////////lampe Salon Rouge////////////////////////
   if(varButtonR == true){
    etatButtonR++;
  }
  if(etatButtonR == 1){
    digitalWrite(ledChR, HIGH);
  }
  else if (etatButtonR == 2){
    digitalWrite(ledChR, LOW);
    etatButtonR = 0;
  }
    ///////////////////////////////////////////////////////
  //////////////Systeme automatic  ////////////////////////
  if (var_servo == HIGH){
    myservo.write(pos = 180);
  }
  else
  myservo.write(pos = 0);
  // put your main code here, to run repeatedly:

}
