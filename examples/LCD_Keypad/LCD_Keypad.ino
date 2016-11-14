// Print the key selection
#include <LiquidCrystal.h>
#include <MD_AButton.h>

// LCD display definitions
#define  LCD_ROWS  2
#define  LCD_COLS  16

// LCD pin definitions
#define  LCD_RS    8
#define  LCD_ENA   9
#define  LCD_D4    4
#define  LCD_D5    LCD_D4+1
#define  LCD_D6    LCD_D4+2
#define  LCD_D7    LCD_D4+3
#define  LCD_KEYS  KEY_ADC_PORT // use default pin

LiquidCrystal	lcd(LCD_RS, LCD_ENA, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
MD_AButton		lcdButton(LCD_KEYS);	

void setup() 
{ 
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();

  lcd.write("MD_AButton Test");
  lcd.setCursor(0,1);
  lcd.write("Press keys ...");

  delay(750);
}

void loop() 
{
  char	c = lcdButton.getKey();

  lcd.home();
  lcd.print("Key =           ");
  lcd.setCursor(6, 0);
  lcd.print((c == KEY_NONE) ? ' ' : c);
  
  delay((c == KEY_NONE) ? 10 : 200 );
}

