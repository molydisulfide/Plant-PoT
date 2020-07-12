#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the Arduino pin number it is connected to:

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  Serial.begin(115200); // initialize the Serial Monitor.
  
  pinMode(A0, INPUT); // call A0 pin on Arduino as the analog input pin for the moisture sensor.
  
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  
  lcd.print("I'm happy ^^"); // Print a message to the LCD.

} 

void loop() {
  //lcd.setCursor(0, 1);
  //lcd.print("THANKS");
  int trip_pin = 8;
  int val = analogRead(trip_pin); // initialize the read value for the moisture input pin.
  Serial.println(val);

  getMoisture(); // execute the Moisture loop.
  
}

void getMoisture() {       
      
    int moistureValue;
    moistureValue=analogRead(A0);
    float m_voltage = moistureValue * (3.3 / 1023.0);   // convert sensor reading to voltage.
    Serial.println("Voltage on moisture sensor is: ");  
    Serial.print(m_voltage); Serial.println(" V");
    delay(1000);
    
    if(m_voltage < 1) {
      
      Serial.print("Signal has tripped at "); Serial.print(m_voltage); Serial.println(" Volts."); 
      // print the read-out value at the moment of loop trip to the Serial Monitor.
      lcd.clear();
      lcd.print("Getting thirsty..."); // change the displayed text on the LCD screen.
      delay(3000);
    }
      else if(m_voltage > 0) {
        
      lcd.clear();
      lcd.print("I'm happy ^^");
      delay(1000);
    }
    
}
