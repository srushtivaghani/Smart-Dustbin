#include <Servo.h>   //servo library
Servo servo;
Servo servo2;     
int trigPin = 5; //5   
int echoPin = 6;   //6
int servoPin = 7;  //7

int trigPin2 = 9;    
int echoPin2 = 11;   
int ledPin = 8;

int led= 10;
long duration, dist, average;
long duration2, dist2, average2;   
long aver[3];   //array for average

long aver2[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach();

    Serial.begin(9600);
    servo2.attach(ledPin);  
    pinMode(trigPin2, OUTPUT);  
    pinMode(echoPin2, INPUT);  
    servo2.write(0);         //close cap on power on
    delay(100);
    servo2.detach(); 
} 

void measure() {  
  digitalWrite(10,HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) / 29.1;    //obtain distance
}
void measure2() {  
  digitalWrite(10,HIGH);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
  dist2 = (duration2/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();     
    measure2();          
   aver[i]=dist;
   aver2[i]=dist2;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;
 dist2=(aver2[0]+aver2[1]+aver2[2])/3;
 Serial.print(dist2);    

if ( dist<50 ) {
//Change distance as per your need
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}
if ( dist2<20 ) {
//Change distance as per your need
 digitalWrite(ledPin, HIGH);      
}
if ( dist2>10 ) {
//Change distance as per your need
 digitalWrite(ledPin, LOW);      
}
Serial.print(dist);
}
