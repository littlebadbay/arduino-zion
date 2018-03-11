// LCD1202_NumberFonts (C)2011 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the included number-fonts,
// and how to use them.
//
// This program requires a Nokia 1202 LCD module.
//
// It is assumed that the LCD module is connected to
// the following pins using a levelshifter to get the
// correct voltage to the module.
//      SCK  - Pin 8
//      MOSI - Pin 9
//      LED   - Pin 10
//      RST  - Pin 11
//      CS   - Pin 12
//

#include <LCD1202_Basic.h>

LCD1202 myGLCD(4,5,6,3,2);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup()
{
  myGLCD.InitLCD();
}

void loop()
{
  for (int i=0; i<=1000; i++)
  {
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumF(float(i)/3, 2, RIGHT, 0);
    myGLCD.setFont(BigNumbers);
    myGLCD.printNumI(i, LEFT, 24);
  }
  
  myGLCD.setFont(SmallFont);
  myGLCD.print("|            |", CENTER, 16);
  delay(500);
  for (int i=1; i<12; i++)
  {
    myGLCD.print("\\", 6+(i*6), 16);
    delay(500);
  }
  myGLCD.clrScr();
}
