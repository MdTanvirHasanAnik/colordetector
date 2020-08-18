#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,3,2,1,0);
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define RedLED 11
#define GreenLED 10
#define BlueLED 9
#define sensorOut 8
int frequencyRed = 0;
int frequencyGreen =0;
int frequencyBlue=0;

void setup() {
  lcd.begin( 16, 2);
  lcd.print("Input Color Plz:");
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  analogWrite(RedLED,0);
  analogWrite(GreenLED, 0);
  analogWrite(BlueLED, 0);
//  Serial.begin(9600);

}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequencyRed = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequencyRed);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyGreen= pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequencyGreen);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyBlue = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequencyBlue);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  analogWrite(RedLED, frequencyGreen);
    analogWrite(GreenLED, frequencyRed);
    analogWrite(BlueLED, frequencyBlue);
   // 
  if(frequencyRed>46 && frequencyRed<65 && frequencyGreen>39 && frequencyGreen<90 && frequencyBlue>60 && frequencyBlue<160 ){
    lcd.clear();
    lcd.print("Your Color Is:");
    lcd.setCursor(0, 1);
    lcd.print("YELLOW");
    delay(3500);
    lcd.clear();
    lcd.print("Input Color Plz:");
    
  }
  //
  else if(frequencyRed>56 && frequencyRed<72 && frequencyGreen>255 && frequencyGreen<275 && frequencyBlue>180 && frequencyBlue<206 ){
    lcd.clear();
    lcd.print("Your Color Is:");
    lcd.setCursor(0, 1);
    lcd.print("RED");
     delay(3500);
    lcd.clear();
    lcd.print("Input Color Plz:");
    
    
  }
   else if(frequencyRed>350 && frequencyRed<380 && frequencyGreen>435 && frequencyGreen<475 && frequencyBlue>310 && frequencyBlue<350 ){
    lcd.clear();
    lcd.print("Your Color Is:");
    lcd.setCursor(0, 1);
    lcd.print("BLACK");
     delay(3500);
    lcd.clear();
    lcd.print("Input Color Plz:");
    
  }
  
  else if(frequencyRed>170 && frequencyRed<200 && frequencyGreen>168 && frequencyGreen<190 && frequencyBlue>190 && frequencyBlue<215 ){
    lcd.clear();
    lcd.print("Your Color Is:");
    lcd.setCursor(0, 1);
    lcd.print("GREEN");
     delay(3500);
    lcd.clear();
    lcd.print("Input Color Plz:");
    
  }
    else if(frequencyRed>160 && frequencyRed<186 && frequencyGreen>260 && frequencyGreen<285 && frequencyBlue>115 && frequencyBlue<140 ){
    lcd.clear();
    lcd.print("Your Color Is:");
    lcd.setCursor(0, 1);
    lcd.print("VIOLET");
     delay(3500);
    lcd.clear();
    lcd.print("Input Color Plz:");
    
    
  }
   else if(frequencyRed>115 && frequencyRed<150 && frequencyGreen>70 && frequencyGreen<100&& frequencyBlue>30 && frequencyBlue<50 ){
    lcd.clear();
    lcd.print("Your Color Is:");
    lcd.setCursor(0, 1);
    lcd.print("Sky Blue");
     delay(3500);
    lcd.clear();
    lcd.print("Input Color Plz:");
    
    
  }
//  else if(frequencyRed>75 && frequencyRed<98 && frequencyGreen>134 && frequencyGreen<170 && frequencyBlue>30 && frequencyBlue<42 ){
//    lcd.clear();
//    lcd.print("Your Color Is:");
//    lcd.setCursor(0, 1);
//    lcd.print("Viloet");
//     delay(3500);
//    lcd.clear();
//    lcd.print("Input Color Plz:");
//    
//  }
//   else if(frequencyRed>57 && frequencyRed<81 && frequencyGreen>52 && frequencyGreen<69 && frequencyBlue>17 && frequencyBlue<29 ){
//    lcd.clear();
//    lcd.print("Your Color Is:");
//    lcd.setCursor(0, 1);
//    lcd.print("Lime Green");
//     delay(3500);
//    lcd.clear();
//    lcd.print("Input Color Plz:");
//    
//  }
//  else if(frequencyRed>30 && frequencyRed<35 && frequencyGreen>98 && frequencyGreen<112 && frequencyBlue>20 && frequencyBlue<25 ){
//    lcd.clear();
//    lcd.print("Your Color Is:");
////    lcd.setCursor(0, 1);
////    lcd.print("Orange");
////     delay(3500);
////    lcd.clear();
////    lcd.print("Input Color Plz:");
//    
//  }
}