#include <LiquidCrystal.h>
#define trigger 8
#define echo 9
#define buzzer 10
#define water A0
int value;
int set=20; 
int  fire_sensor=11;
int fire_value;
LiquidCrystal lcd(2,3,4,5,6,7);
 
float time=0,distance=0;
 
void setup()
{
 Serial.begin(9600); 
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(buzzer,OUTPUT);
 lcd.print(" Ultra sonic");
 lcd.setCursor(0,1);
 lcd.print("Distance Meter");
 delay(2000);
 lcd.clear();

}
 
void loop()
{
 lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 lcd.clear();
 Serial.print("Distance:");
 Serial.print(distance);
 Serial.print("cm..");
 lcd.print("Distance:");
 lcd.print(distance);
 lcd.print("cm");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
 lcd.print(distance/100);
 lcd.print("m");
 delay(500);
 if(distance<=10)
 {
  lcd.clear();
  lcd.print("bin filled");
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
  }
  else
  {
  digitalWrite(buzzer,LOW);
}
getwaterValue();
getfire();
}


void getwaterValue()
 {
  value = analogRead(water);
  

 //Serial.println(value);
 //value = map(value,0,1023,225,0);
 Serial.println(value);
 lcd.clear();
 if(value<=300)
 {
  digitalWrite(buzzer,HIGH);
  delay(2000);
  lcd.print("water detected");
 }
 else
 {
  lcd.print("no  detected");
 }
 delay(1000);
 lcd.clear();
 }

void getfire()
{
  fire_value=digitalRead(fire_sensor);
  if(fire_value==LOW)
  {
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(1000);
  }
  else
  {
  digitalWrite(buzzer,LOW);
  delay(100);
  }
}
