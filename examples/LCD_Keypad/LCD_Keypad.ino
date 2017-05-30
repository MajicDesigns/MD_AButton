// Example program for MD_AButton library
//
// Print the switch pressed to the Serial Monitor
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
MD_AButton    lcdButton(LCD_KEYS);

void setup() 
{ 
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();

  lcd.print("MD_AButton Test");
  lcd.setCursor(0,1);
  lcd.print("Press keys ...");
}

void loop() 
{
  char	c = lcdButton.getKey();

  if (c != '\0')
  {
    lcd.home();
    lcd.print("Key =           ");
    lcd.setCursor(6, 0);
    lcd.print((c == KEY_NONE) ? ' ' : c);
  }
}
