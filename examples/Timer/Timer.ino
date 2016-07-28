#include <LiquidCrystal.h>
#include <LcdProgressBar.h>

byte lcdNumCols = 16; // -- number of columns in the LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LcdProgressBar lpg(&lcd, 1, lcdNumCols);

unsigned long duration = 2000; // 2000 milliseconds, 2 seconds
unsigned long startedMillis  = 0;

void setup() {
  //-- Only useful for debugging purpose
  Serial.begin(9600);

  //-- initializing the LCD
  lcd.begin(2, lcdNumCols);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("LcdProgressBar");
      
  delay(100);

  //-- initializing the progress bar
  initLpg();
}

//-- initializing the progress bar
void initLpg()
{
  //-- start time
  startedMillis = millis();

  //-- Set min and max values
  lpg.setMinValue(startedMillis);
  lpg.setMaxValue(startedMillis + duration);

  //-- Draw it: the frame
  lpg.draw(startedMillis);
}

void loop() {

  unsigned long currentMillis = millis();

  //-- draw progress bar
  lpg.draw(currentMillis);

  if ((unsigned long)(currentMillis - startedMillis) > duration) {
    //--- Duration's over: delay and start again!
    delay(900);
    initLpg();
  }

  // -- do some delay: frequent draw may cause broken visualization
  delay(100);
}

