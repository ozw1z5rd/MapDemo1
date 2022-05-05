#include "Common.h"
#include "System_Graphics.h"
#include "System_CharacterSets.h"
#include <peekpoke.h>
#include <string.h>

byte PosX = 23;
byte PosY = 16;
byte Height = 8;
byte Width = 16;
byte MessageWindow[16*8];
byte MessageWindowColors[16*8];
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
    
    DrawLineH('0', 1, 22, 0, 17);
    DrawLineH('0', 1, 22, 24, 17);
    DrawLineV('0', 1, 22, 0, 24);
    DrawLineV('0', 1, 39, 0, 25);
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