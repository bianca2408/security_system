#include <SoftwareSerial.h>

#define FORCE_SENSOR_PIN1 A0
#define FORCE_SENSOR_PIN2 A1
#define FORCE_SENSOR_PIN3 A2 
int buzz = 5;
int pir1 = 8;
int pir2 = 9;
int pir3 = 4;

SoftwareSerial blue(2,3);

void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pir3, INPUT);
  Serial.begin(9600);
  blue.begin(9600);  
}

void loop() {
  int analogReading1 = analogRead(FORCE_SENSOR_PIN1);
  int analogReading2 = analogRead(FORCE_SENSOR_PIN2);
  int analogReading3 = analogRead(FORCE_SENSOR_PIN3);

  int status1 = digitalRead(pir1);
  int status2 = digitalRead(pir2);
  int status3 = digitalRead(pir3);
  int room1=0;
  int room2=0;
  int room3=0;
   
 

  if(status1 == HIGH && analogReading1 >= 50)
      room1=1;
  if(status2 == HIGH && analogReading2 >= 50)
      room2=1;
  if(status3 == HIGH && analogReading3 >= 50)
      room3=1;

  if(room1 == 1)
    {
      Serial.println("ALERT! Presence detected in room 1.");
      tone(buzz,100,1000);      
    }
  if(room2 == 1)
    {
      Serial.println("ALERT! Presence detected in room 2.");
      tone(buzz,100,1000);  
    }
  if(room3 == 1)
    {
      Serial.println("ALERT! Presence detected in room 3.");
      tone(buzz,100,1000);  
    }
  if(room1 == 1 && room2 == 1)
    {
      Serial.println("ALERT! Presence detected in room 1 and room 2.");
      tone(buzz,100,1000);  
    }
  if(room1 == 1 && room3 == 1)
    {
      Serial.println("ALERT! Presence detected in room 1 and room 3.");
      tone(buzz,100,1000);  
    }
  if(room2 == 1 && room3 == 1)
    {
      Serial.println("ALERT! Presence detected in room 2 and room 3.");
      tone(buzz,100,1000);  
    }
  if(room1 == 1 && room2 == 1 && room3 == 1)
    {
      Serial.println("ALERT! Presence detected in all rooms.");
      tone(buzz,100,1000);  
    }                                       
delay(1000);  
} 

////////////////////////////////////////////////////////////////////////////////////////////////////

