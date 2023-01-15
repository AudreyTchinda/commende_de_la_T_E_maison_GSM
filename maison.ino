#include <GPRS_Shield_Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>
int distance;
long temp_actuel;
boolean GSM_stop = 0;

const int TrigPin = 2;
const int EchoPin = 3;

#define MESSAGE_LENGTH 15
char msg[MESSAGE_LENGTH];
int messageIndex = 0;

char phone[16], datetime[24];
String msg1, num;
#define vnum "+237651729723"
GPRS gprs(7, 8, 9600);

#define led 5
#define buzz 6

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  gprs.checkPowerUp();
  while (!gprs.init()) {
    delay(1000);    Serial.println("eror");
  }
  while (!gprs.isNetworkRegistered()) {
    delay(10);
  }
  digitalWrite(buzz, HIGH);
  delay(1000); 
  digitalWrite(buzz, LOW);
  // put your setup code here, to run once:

}

void loop() {
  dist();
GET();
  if ( distance <= 50 and GSM_stop == 0) {
    digitalWrite(led, HIGH);
    digitalWrite(buzz, HIGH);
    gprs.callUp(vnum);Serial.println("call");temp_actuel=millis(); 
    while((millis()<temp_actuel+60000) and ( GSM_stop == 0)){
GET();}
    }
     
  if (distance > 50){GSM_stop = 0; temp_actuel=0;}

  // put your main code here, to run repeatedly:

}
void dist(){
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  distance = pulseIn(EchoPin, HIGH) / 58.00;
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(500);}
