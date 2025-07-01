#include<Servo.h>
Servo Myservo;
#define trigPin 10           // Trig Pin Of HC-SR04
#define echoPin 9        // Echo Pin Of HC-SR04
#define trigout 8                   //left motor 1st pin

int pos;
long duration, distance;


void setup()
{
  Myservo.attach(3);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);       // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);        //Set Echo Pin As I/P To Receive Reflected Waves
  pinMode(trigout, OUTPUT);
}


void loop() 
{
  Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;                       // Get Distance
  Serial.println(distance);
  delay(10);
  if (distance <15 && distance >0)               // Condition For Absence Of Obstacle            
  {
    for(pos=0;pos<=20;pos++)
    {
    Myservo.write(pos);
    delay(15);
    }
    for(pos=20;pos>=0;pos--)
    {
    Myservo.write(pos);
    delay(15);                                                 
    }
    delay(5000);
  }
}
