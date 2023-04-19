#include <HX711_ADC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C library
#define ledPin 7
#define buzz 8
HX711_ADC LoadCell(4, 5); // dt pin, sck pin
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD HEX address 0x27
int taree = 6;
int a = 0;
float b = 0;

void setup() {
  Serial.begin(57600);
  pinMode (taree, INPUT_PULLUP);
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(1000); // load cells gets 1000ms of time to stabilize

  /////////////////////////////////////
  LoadCell.setCalFactor(475); // Calibarate your LOAD CELL with 100g weight, and change the value according to readings
  /////////////////////////////////////
  
  lcd.begin(); // begins connection to the LCD module
  lcd.backlight(); // turns on the backlight
  
  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print(" IOT BASED IV"); // print out to LCD
  lcd.setCursor(0, 1); // set cursor to first row
  lcd.print(" BAG MONITORING "); // print out to LCD
  delay(2000);
  lcd.clear();

  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("   PROJECT BY "); // print out to LCD
  delay(2000);
  lcd.clear();

  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("OMCKAR NIRMITEE"); // print out to LCD
  lcd.setCursor(0, 1); // set cursor to first row
  lcd.print(" PRATHAMESH "); // print out to LCD
  delay(2000);
  lcd.clear();
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzz, OUTPUT);
}
void loop() { 
  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("Digital Scale "); // print out to LCD 
  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
  Serial.println(i);
  if(LoadCell.getData() <= 150){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  if(LoadCell.getData() <= 50){
    digitalWrite(buzz, HIGH);
  }else{
    digitalWrite(buzz, LOW);
  }
  
 if (i<0)
 {
  i = i * (-1);
  lcd.setCursor(0, 1);
  lcd.print("-");
   lcd.setCursor(8, 1);
  lcd.print("-");
 }
 else
 {
   lcd.setCursor(0, 1);
  lcd.print(" ");
   lcd.setCursor(8, 1);
  lcd.print(" ");
 }
  
  lcd.setCursor(1, 1); // set cursor to secon row
  lcd.print(i, 1); // print out the retrieved value to the second row
  lcd.print("g ");
  float z = i/28.3495;
  lcd.setCursor(9, 1);
  lcd.print(z, 2);
  lcd.print("oz ");

  if (i>=5000)
  {
    i=0;
  lcd.setCursor(0, 0); // set cursor to secon row
  lcd.print("  Over Loaded   "); 
  delay(200);
  }
  if (digitalRead (taree) == LOW)
  {
    lcd.setCursor(0, 1); // set cursor to secon row
    lcd.print("   Taring...    ");
    LoadCell.start(1000);
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
}
