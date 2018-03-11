// LCD1202_ViewFont (C)2011 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the included full font.
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

void setup()
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
  myGLCD.clrScr();
  myGLCD.print("Upper case:", LEFT, 0);
  myGLCD.print("ABCDEFGHIJKLM", CENTER, 16);
  myGLCD.print("NOPQRSTUVWXYZ", CENTER, 24);
  delay (5000);
  
  myGLCD.clrScr();
  myGLCD.print("Lower case:", LEFT, 0);
  myGLCD.print("abcdefghijklm", CENTER, 16);
  myGLCD.print("nopqrstuvwxyz", CENTER, 24);
  delay (5000);
  
  myGLCD.clrScr();
  myGLCD.print("Numbers:", LEFT, 0);
  myGLCD.print("0123456789", CENTER, 16);
  delay (5000);
  
  myGLCD.clrScr();
  myGLCD.print("Special:", LEFT, 0);
  myGLCD.print("!\"#$%&'()*+,-.", CENTER, 16);
  myGLCD.print("/:;<=>?@[\\]^_`", CENTER, 24);
  myGLCD.print("{|}~", CENTER, 32);
  delay (5000);
}