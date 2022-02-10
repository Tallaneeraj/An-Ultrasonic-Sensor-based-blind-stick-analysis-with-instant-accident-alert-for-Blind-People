#include <LiquidCrystal.h>
#define sensor 8

LiquidCrystal lcd(2,3,4,5,6,7);
void setup()
{
  lcd.begin(16,2); //lcd module
  lcd.print("Accident detector");
 delay(1000);
  lcd.setCursor(2,1);
 delay(1000);
 lcd.print(" system");
  Serial.begin(9600); //Baud rate of the GSM/GPRS Module
  pinMode(sensor,INPUT);
   
  //digitalWrite(button,HIGH);
  
}
void sms()
{
 
Serial.print("\r");
  delay(1000);
  //Serial.print(“AT+CMGF=1\r”);
  Serial.print("AT+CMGF=1\r");
  delay(1000);
  lcd.clear();
  lcd.print("Finding location");
  lcd.setCursor(2,2);
  lcd.print("sending SMS");
  lcd.setCursor(2,2);
 // Serial.print(“AT + CMGS = \”+919948896119\”\r”);
  Serial.print("AT+CMGS=\"+916303451818\"\r");    
  delay(1000);
  Serial.print("accident detected location ");   
  delay(1000);
  Serial.print(" https://maps.app.goo.gl/CzsDuNrZ9gWCSxHb6");   
  delay(1000);
  //Serial.print("");   
  //delay(1000);
  Serial.write(0x1A);
  delay(1000);  
}
void loop()
{
  //setup();
  if(digitalRead(sensor)==1)
  {
    
    sms();
    delay(2000);
  }
 if(digitalRead(sensor)==0)
 {
  lcd.clear();
  lcd.print("    welcome");
  delay(1000);
 }
}
