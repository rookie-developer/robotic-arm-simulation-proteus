//check out my youtube channel :https://www.youtube.com/channel/UC92gG4BBWAYu4vw_OgsgSLA?view_as=subscriber

#include<LiquidCrystal.h>
#include<Servo.h>

#define button1 22
#define button2 23
#define button3 24
#define button4 25
#define button5 26
#define button6 27
#define button7 28

Servo servo1;
Servo servo2;
Servo servo3;
LiquidCrystal lcd(14,15,16,17,18,19);



int pos1 = 93; // for motor 1
int posl1=pos1;
int pos2 = 93; // for motor 2
int posl2=pos2; 
int pos3 = 93; // for motor 3
int posl3=pos3; 

void intro()      //// this is a silly intro you can delete if you want
{
  lcd.setCursor(0,0);
  lcd.print("Rookie_developer");
  lcd.setCursor(0,1);
  lcd.print("presents");
  delay(1000);
  lcd.clear();delay(500);
  lcd.setCursor(3,0);lcd.print("**robotic ARM**");delay(1000);
  lcd.clear();delay(500);
}

void action1()     /// this is to control servo 1
{
  servo1.write(pos1);
  lcd.setCursor(13,0);
  lcd.print(posl1);  
  if(digitalRead(button2)==0)
  {
    pos1++;posl1=pos1;delayMicroseconds(2);
  }else if(digitalRead(button3)==0)
  {
    pos1--;posl1=pos1;delayMicroseconds(2);
  }
  if(posl1<43){posl1=43;}
  else if(posl1<10){lcd.setCursor(14,0);lcd.print("   ");}
  else if(posl1<100){lcd.setCursor(15,0);lcd.print("   ");}
  else if(posl1>143){posl1=143;}
}

void action2()    /// this is to control servo 2
{
  servo2.write(pos2);
  lcd.setCursor(13,1);
  lcd.print(posl2);  
  if(digitalRead(button4)==0)
  {
    pos2++;posl2=pos2;delay(2);
  }else if(digitalRead(button5)==0)
  {
    pos2--;posl2=pos2;delay(2);
  }
  if(posl2<43){posl2=43;}
  else if(posl2<10){lcd.setCursor(14,1);lcd.print("   ");}
  else if(posl2<100){lcd.setCursor(15,1);lcd.print("   ");}
  else if(posl2>143){posl2=143;}
}

void action3()      /// this is to control servo 3
{
  servo3.write(pos3);
  lcd.setCursor(13,2);
  lcd.print(posl3);  
  if(digitalRead(button6)==0)
  {
    pos3++;posl3=pos3;delay(2);
  }else if(digitalRead(button7)==0)
  {
    pos3--;posl3=pos3;delay(2);
  }
  if(posl3<43){posl3=43;}
  else if(posl3<10){lcd.setCursor(14,2);lcd.print("   ");}
  else if(posl3<100){lcd.setCursor(15,2);lcd.print("   ");}
  else if(posl3>143){posl3=143;}
}

///////////////////////////////////////here is the setup and loop ////////////////////////////////////////////////////////

void setup() 
{
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  
  lcd.begin(20,4);
  
  for(int i=22;i<30;i++)
  {
    pinMode(i,INPUT);
  }
  intro();cli();
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("press START");
  lcd.setCursor(0,1);lcd.print("to start controle");

  
  if(digitalRead(button1)==0)
  {
    sei();    
    lcd.clear();delay(200);lcd.setCursor(0,0);
    lcd.print("initialising");delay(500);
    lcd.clear();delay(200);

    
    while(1)
    {
      lcd.setCursor(0,0);
      lcd.print("servo num1 :");
      lcd.setCursor(0,1);
      lcd.print("servo num2 :");
      lcd.setCursor(0,2);
      lcd.print("servo num3 :");
      lcd.setCursor(0,3);
      lcd.print("START to go back");
      action1();
      action2();
      action3();
  
      if(digitalRead(button1)==0)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("controle interrupted");delay(1000);
        break;
      }
    }
        cli();lcd.clear();delay(500);
  }
}
