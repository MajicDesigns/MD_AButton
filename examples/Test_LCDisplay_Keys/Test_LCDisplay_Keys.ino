// Example program for MD_AButton library
//
// Determine the calibration values for the keys on 
// the LCD display menu pad
//
#include <LiquidCrystal.h>
#include <MD_AButton.h>

// LCD display definitions
const uint8_t LCD_ROWS = 2;
const uint8_t LCD_COLS = 16;

// LCD pin definitions
const uint8_t LCD_RS = 8;
const uint8_t LCD_ENA = 9;
const uint8_t LCD_D4 = 4;
const uint8_t LCD_D5 = LCD_D4+1;
const uint8_t LCD_D6 = LCD_D4+2;
const uint8_t LCD_D7 = LCD_D4+3;
const uint8_t LCD_KEYS = KEY_ADC_PORT; // use default pin

LiquidCrystal lcd(LCD_RS, LCD_ENA, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() 
{ 
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();

  lcd.write("Keys Calibrate");
  lcd.setCursor(0,1);
  lcd.write("Press keys ...");

  pinMode(KEY_ADC_PORT, INPUT);
}

void loop() 
{
  int adcKeyIn;

  adcKeyIn = analogRead(KEY_ADC_PORT);    // read the value from the port  
  
  lcd.home();
  lcd.print("Value = ");
  lcd.print(adcKeyIn);
  lcd.print("   ");
  
  delay(100);
}

