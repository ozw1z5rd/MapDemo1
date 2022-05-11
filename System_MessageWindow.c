#include "Common.h"
#include "System_Graphics.h"
#include "System_CharacterSets.h"
#include <peekpoke.h>
#include <string.h>
#include <stdio.h>
#include "BFRPG.h"
#include "Lists.h"

byte PosX = 22;
byte PosY = 14;
#define Height 10
#define Width 17
byte MessageWindow[Width*Height];
byte MessageWindowColors[Width*Height];
byte x, y;
int addressChar, addressColor;

char Messages[64][16] = {
    "Hello there!@",
    "This is a sign@",
    "Wizard's Forest@"};



void DrawMessageWindow()
{
    addressChar = (int)&ScreenDoubleBuffer[0] + PosX + COLS*(PosY);
    addressColor = addressChar + 1000;
    for (y = 0; y < Height; ++y)
        {
            //SetScreenChar(MessageWindow[x + Height*y], PosX + x, PosY + (y * COLS));
            //memcpy((int*)address, &MessageWindow[y * Width], Width);
            CopyMemory((int) addressChar, (int) &MessageWindow[y * Width], Width);
            CopyMemory((int) addressColor, (int) &MessageWindowColors[y * Width], Width);
            //memcpy(address + 0x1000,&(AttributeSet[0][MessageWindow[Width * x]]), Width);
            addressChar += COLS;
            addressColor += COLS;
            //POKEW(tileaddress, PEEKW(&MessageWindow[x * 2][y]));
            //POKEW(tileaddress + 0x1000, PEEKW(&AttributeSet[0][MessageWindow[x * 2][y]]));
        }
}
void BlankMessageWindow()
{
    for (x = 0; x < Width * Height; ++x)
    {
        MessageWindow[x] = ' ';
        MessageWindowColors[x] = 0;
    }
    DrawMessageWindow();
    
  DrawBorder(PosX - 1, PosY - 1, Width + 2, Height + 2, true);
  CopyDoubleBuffer();
}

void ScrollMessageWindowUp(byte lines)
{
  for (y = 0; y < lines; ++y)
  {
    for (x = 0; x < Height * Width - Width; ++x)
    {
      MessageWindow[x] = MessageWindow[x + Width];
      MessageWindowColors[x] = MessageWindowColors[x + Width];
    }
    
    for (; x < Width * Height; ++x)
    {
      MessageWindow[x]= ' ';
      MessageWindowColors[x] = 0;
    }
    DrawMessageWindow();
  }
}

void WriteLineMessageWindow(char message[16], byte delay)
{
    ScrollMessageWindowUp(1);  
    for(x = 0; x < Width; ++x)
    {
      if (message[x] == '@')
      {
        while (x < Width)
        {
            MessageWindow[(Width*Height - Width) + x] = ' ';
            MessageWindowColors[(Width*Height - Width) + x] = 0;
            ++x;
        }
        break;
      }
      else
      {
        MessageWindow[(Width*Height - Width) + x] = message[x];
        MessageWindowColors[(Width*Height - Width) + x] = AttributeSet[message[x]];
      }
      SetScreenCharColor(message[x], AttributeSet[message[x]], PosX + x, PosY + Height - 1);
      if (delay > 0)
      {
        wait_vblank(delay);
        CopyDoubleBufferArea(PosX, PosY, Width, Height);
        //CopyDoubleBuffer();
      }
    }
  if (delay == 0)
    CopyDoubleBufferArea(PosX, PosY, Width, Height);
    //CopyDoubleBuffer();      
    
}

void DrawCharStats(byte characterIndex)
{
  byte statX = PosX;
  byte statY = 2 + characterIndex * 3;
  playerChar *PlayerChar = getPlayerChar(characterIndex);
  
  DrawBorder(statX - 1, statY - 1, COLS - statX + 1, 4, false);
  sprintf(str, "%s@", RaceDescription[PlayerChar->RACE].NAME);
  PrintString(str, statX, statY, false, false);
  sprintf(str, "HP:%d/%d@", PlayerChar->HP, PlayerChar->HPMAX);  
  PrintString(str, statX + 9, statY, false, false);
  sprintf(str, "%s@", ClassDescription[PlayerChar->CLASS].NAME);
  PrintString(str, statX, statY + 1, false, false);
  ReverseBufferArea(statX - 1, statY - 1, COLS - statX + 1, 5);
  CopyDoubleBufferArea(statX - 1, statY - 1, COLS - statX + 1, 5);
  
  sprintf(str, "HPMAX:%d@", PlayerChar->HPMAX);
  WriteLineMessageWindow(str, false);
  sprintf(str, "STR:%d@", PlayerChar->STR);
  WriteLineMessageWindow(str, false);
  sprintf(str, "DEX:%d@", PlayerChar->DEX);
  WriteLineMessageWindow(str, false);
  sprintf(str, "CON:%d@", PlayerChar->CON);
  WriteLineMessageWindow(str, false);  
  sprintf(str, "INT:%d@", PlayerChar->INT);
  WriteLineMessageWindow(str, false);  
  sprintf(str, "WIS:%d@", PlayerChar->WIS);
  WriteLineMessageWindow(str, false);  
  sprintf(str, "CHR:%d@", PlayerChar->CHR);
  WriteLineMessageWindow(str, false);  
}