// Determine the values for the keys in the LCD display menu pad
#include <LiquidCrystal.h>

// LCD display definitions
#define  LCD_ROWS  2
#define  LCD_COLS  16

#define  KEY_ADC_PORT  A0

// LCD pin definitions
#define  LCD_RS    8
#define  LCD_ENA   9
#define  LCD_D4    4
#define  LCD_D5    LCD_D4+1
#define  LCD_D6    LCD_D4+2
#define  LCD_D7    LCD_D4+3

static LiquidCrystal lcd(LCD_RS, LCD_ENA, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() 
{ 
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();

  lcd.write("Keypad Testing");
  lcd.setCursor(0,1);
  lcd.write("Press keys ...");

//  pinMode(KEY_ADC_PORT, INPUT_PULLUP);
  pinMode(KEY_ADC_PORT, INPUT);
  
  delay(750);
}

void loop() 
{
  int adcKeyIn;

  adcKeyIn = analogRead(KEY_ADC_PORT);    // read the value from the sensor  
  
  lcd.home();
  lcd.print("Value = ");
  lcd.print(adcKeyIn);
  lcd.print("   ");
  
  delay(100);
}

