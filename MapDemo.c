//#link "Common.c"
//#link "Screen_Map.c"
//#link "System_Input.c"
//#link "System_Graphics.c"
//#link "System_CharacterSets.c"
//#link "System_MessageWindow.c"
//#link "Screen_Title.c"
//#link "System_MusicPlayer.c"

#include <conio.h>
#include <c64.h>

#include "Common.h"
#include "Screen_Map.h"
#include "Screen_Title.h"
#include "System_Input.h"
#include "System_Graphics.h"
#include "System_CharacterSets.h"
#include "System_MessageWindow.h"
#include "System_MusicPlayer.h"

void Initialize()
{
  ScreenDisable();
  bgcolor(0);
  bordercolor(0);

  InitializeInput();
  setcolortextmode();
  SetCharacterSet();
  Draw_Title();
  InitializeMapData();
  DrawEntireMap();
  BlankMessageWindow();

  //WriteLineMessageWindow("TheQuickBrownFox", 0);
  //WriteLineMessageWindow("JumpsOverLazyDog", 0);
  //WriteLineMessageWindow("0123456789:;<=>?", 0);
  //WriteLineMessageWindow(" ! #$%&'()*+,-./", 0);
  
  ScreenEnable();
  
}

void main(void)
{
  Initialize();
  
  while(true)
  {
    UpdateInput();
    Graphics_Update();
    music_update();
    
    //if(InputChanged())
    {
      CheckInput();
    }
    SetChar(0, 0, 1);
    
  }
}