# include "LiquidCrystal.h"  //lcd libary                                       
LiquidCrystal lcd(7,6,5,4,3,2);   //LCD object Parameters: (rs, enable, d4, d5, d6, d7)

const int trigPin = 10; //trig pin connection 
const int echoPin = 11;  //echopin connection 
long duration;
int distanceCm;
int lvl;
// float liquid;
int max=1020;
float temp;
                                                                                                            
void setup() { 
  Serial.begin(9600);  
  // setup perameter
  lcd.begin(16,2);                                                   
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0,0);
  lcd.print("  WaterLevel    ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("  Measurement  ");
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    Made By    ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(" MD.Tanvir Hasan  ");
  //Serial.println("Water_Level_Controller");
  //Serial.println("Motor_mode    Water_level");
  
  delay(300);
  
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(12,LOW);
  lcd.clear();
}

void loop() {   // loop of flow program
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;                                                                                 
  //lcd.setCursor(0,0); 

  lvl=distanceCm;                                                
  //lcd.print("NOW_AT:");
  //lcd.print(lvl);
  //lcd.setCursor(0,1);
  
  //lcd.print("LEVEL:");
  //lcd.print(distanceCm);
  temp = (lvl)*(100.00/(max-20));
  if(temp<100){
    lcd.setCursor(0,0);
    lcd.print("LEVEL: ");
    
    lcd.print(temp);
    lcd.print(" % "); //cm

    lcd.setCursor(0,1);
    lcd.print("--- MOTOR_ON ---"); 

    Serial.println("ON");
    Serial.println(temp);
    //motor control
    digitalWrite(8,HIGH);
    digitalWrite(9,150);
    delay(150);
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("LEVEL:");
    lcd.print("100% MAX");

    lcd.setCursor(0,1);
    lcd.print("-- MOTOR_OFF ---"); 
    Serial.println("OFF");
    Serial.println(100);
    //motorcontrol
    digitalWrite(8,LOW);
    digitalWrite(9,150);
    delay(150);

    }
  delay(10);
}
