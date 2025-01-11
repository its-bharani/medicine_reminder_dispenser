#include<Wire.h>
#include <LiquidCrystal.h>
#include<DS3231.h>
#include <Servo.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DS3231 rtc;
byte incom_value_hr;
byte incom_value_min;
byte incom_value_hr_2;
byte incom_value_min_2;
byte deci;//deciding variable for medicine
Servo servo1, servo2;
int play=11;
int Hor;
int pos = 0;
int Min;

int Sec;
bool h12;
bool hPM;
int Mon;//month
int Date;
int Yr;
bool month;

char text;

void setup()

{ 
  Serial.begin(9600);
  pinMode(play,OUTPUT);//settting play as output;
  Wire.begin();

  servo1.attach(9);
  servo2.attach(10);
  lcd.begin(16,2);  
  lcd.setCursor(0,0);

  lcd.print("Hi! I am");
  lcd.setCursor(0,1);

  lcd.print("Medibot  :)");
  digitalWrite(play,HIGH);
  digitalWrite(play,LOW);

  //delay(1000);
  //
//h12=false;
//hPM=false;
  // The following lines can be uncommented to set the date and time
  //rtc.setDoW(Friday);  // Set Day-of-Week to SUNDAY
  //rtc.setHour(12);  // Set the time to 7(24hr format)
  //rtc.setMinute(01);
  //rtc.setSecond(00);
  //rtc.setDate(12);// Set the date to January 1st, 2014
  //rtc.setMonth(8);
  //rtc.setYear(23);
  delay(2000);
    
}





void loop()

{



byte Hour = rtc.getHour(h12, hPM);

  Min = rtc.getMinute();

  Sec = rtc.getSecond();
  Date=rtc.getDate();
byte Mon=rtc.getMonth(month);
  Yr=rtc.getYear();
  lcd.setCursor(0,0);

  lcd.print("Time: ");
  lcd.print(Hour);
  lcd.print(":");
  lcd.print(Min);
  lcd.print(":");
  lcd.print(Sec);

 lcd.setCursor(0,1);

 lcd.print("Date: ");
  lcd.print(Date);
  lcd.print("/");
  lcd.print(Mon);
  lcd.print("/");
  lcd.print(Yr);


  
if(Serial.available()>0)
  { 
    deci=Serial.read();
    Serial.print(deci);
    if(deci==00000000){
    incom_value_hr=Serial.read();
    incom_value_min=Serial.read();
    Serial.println(deci);
    Serial.println(incom_value_hr);
    Serial.println("\n");
    Serial.println(incom_value_min);
    Serial.println("\n");}
    else{
      incom_value_hr_2=Serial.read();
    incom_value_min_2=Serial.read();
   // Serial.print(deci);
    Serial.print(incom_value_hr_2);
    Serial.print("\n");
    Serial.print(incom_value_min_2);
    Serial.print("\n");}
    }
    
 if( Hour == incom_value_hr && (Min == incom_value_min || Min == incom_value_min+1)) //Comparing the current time with the Alarm time

{


lcd.clear();

lcd.print("Time for");
Serial.println("alarm on!");

lcd.setCursor(0,1);
lcd.print("Medicine");

digitalWrite(play,HIGH);//to play alarm
delay(1000);
digitalWrite(play,LOW);
delay(100);

} 

if( Hour == incom_value_hr && (Min ==incom_value_min && Sec == 00))
{
 for (pos = 0; pos <= 360; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 360; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
} 



if( Hour == incom_value_hr_2 && (Min == incom_value_min_2|| Min == incom_value_min_2+1)) //Comparing the current time with the Alarm time

{


lcd.clear();

lcd.print("Time for");
Serial.println("alarm on!");

lcd.setCursor(0,1);
lcd.print("Medicine");

digitalWrite(play,HIGH);//to play voice 
delay(1000);
digitalWrite(play,LOW);
delay(100);

} 

if( Hour == incom_value_hr_2 && (Min == incom_value_min_2 && Sec == 00))
{
 for (pos = 0; pos <= 360; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 360; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
} 

}
