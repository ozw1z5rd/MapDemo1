#include "System_Input.h"
#include "System_Graphics.h"
#include "System_MessageWindow.h"
#include "Common.h"
#include <stdio.h>
#include "SIDPlayer.h"

byte yscroll;
/*byte sinevalue[32] = {12,14,17,19,20,22,23,24,
24,24,23,22,20,19,17,14,
12,10,7,5,4,2,1,0,
0,0,1,2,4,5,7,10};*/
byte xcredit;
byte delay;
byte xoff;
bool skipline;

#define linecount 14

char CreditsLines[][20] =
{
  "Credits@",
  "(c) 2022@",
  "All rights reserved@",
  
  "Lead Designer@",
  "and Programmer:@",
  "Somebody@",
  
  "Makes use of the@",
  "following@",
  "libraries@",
  
  "C/ASM SID Player:@",
  "https://github.com/@",
  "solidcore-commodore@",
  
  "Special Thanks@",
  "YOU!@"
  };

void ScrollUp()
{
  byte i = 0;  
  yscroll--;
  VIC.ctrl1 = VIC.ctrl1 & 0xf8;
  VIC.ctrl1 |= (yscroll & 7);
  if ((yscroll & 7) == 7)
  {
    MoveScreenUp();
    if (xcredit < linecount)
    {
      if (xoff %4 != 0)
      {
        PrintString(CreditsLines[xcredit], xcredit % 3, 24, true, false);
        ++xcredit;   
      }
      else
        PrintString("@", xcredit % 3, 24, true, false);
        
    }
      
    ++xoff;
  }
  if (xcredit == linecount)
  {
    //char str[3];
    ++delay;
    //sprintf(str,"%d@", delay);
    //PrintString(str, xcredit % 2, 24, true, false);
    
  }
  wait_vblank(2);
}

screenName Update_Credits()
{
  byte temp = VIC.ctrl1;
  screenName nextScreen = Title;
  bool exit = false;
  yscroll = 0;
  xcredit = 0;
  delay = 0;
  xoff = 0;
  skipline = false;
  
  ClearScreen();
  PlaySID();
  
  while (!exit)
  {
    UpdateInput();
    ScrollUp();
    
    if (InputChanged())
      if (InputFire())
        exit = true;
    if (delay == 200)
      exit = true;
  }
  StopSID();
  VIC.ctrl1 = temp;
  return nextScreen;
}