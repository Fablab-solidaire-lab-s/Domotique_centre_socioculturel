#include <Servo.h>
// variables pin
int photoresistance = A0; // la photorésistance est connecté au pin

int buttonPin1 = 2;
int buttonPin2 = 4;
int buzzerPin = 11;
int led = 13;
int led1 = 12;
int buttonPir = 7;
int led2 = 9;
int led3 = 3;
int buttonPin3 = 8;
int inputPin = 6;
int pin_servo = 5;
//initialisation
int photocellReading; // lecture de la photorésistance
int varPir;
int etatButton = 0;
int etatButton1 = 0;
int etatButton2 = 0;
int val1 = 0;
int pos = 0;
 Servo myservo; 
void setup() {

  Serial.begin(9600);

  pinMode(led3, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPir, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin3, INPUT);
   pinMode(inputPin, INPUT);
   myservo.attach(pin_servo);
}

void loop() {
  //lecture variable
  int varButton1 = digitalRead(buttonPin1);
  int val_button2 = digitalRead(buttonPin2);
  int var = digitalRead(buttonPin3);

  delay(200);

  photocellReading = analogRead(photoresistance);
  varPir = digitalRead(buttonPir);
  val1 = digitalRead(inputPin);
  ////////////////////////systeme eclairage automatique///////////////////////
  if (photocellReading < 300) {
    digitalWrite(led3, HIGH);
  }
  else
  {
    digitalWrite(led3, LOW); 
  }

  //////////////////////////////////////////////////////////////////////////

  ///////////////////////////// systeme alerte ////////////////////////////
  if (varButton1 == true) {
    etatButton++;
    Serial.println(etatButton);
  }

  if (etatButton == 1) {
    digitalWrite(led, HIGH);

    if (varPir == true) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(led1, HIGH);
    }
  }

  else if (etatButton == 2) {
    digitalWrite(led, LOW);
    etatButton = 0;
  }


  if (val_button2 == true ) {
    // Serial.println(val_button2);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led1, LOW);

  }
  //////////////////////////////////////////////////////////////////////////


  ///////////////////////////// lampe salon ////////////////////////////

  if ( var == true) {
    etatButton2++;

  }
  if (etatButton2 == 1) {
    digitalWrite(led2, HIGH);
  }
  else if (etatButton2 == 2) {
    digitalWrite(led2, LOW);
    etatButton2 = 0;
  }
  //////////////////////////////////////////////////////////////////////////
  ///////////////////////////// systeme porte automatic ////////////////////////////
  if (val1 == HIGH) {
   
  
      myservo.write(pos=180);
      
       }
   
  
  else  
   
      myservo.write(pos =0);
   
       
}
