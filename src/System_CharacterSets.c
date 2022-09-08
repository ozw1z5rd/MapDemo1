#include "Common.h"
#include "Platform.h"
//#link "CharacterSetASM.s"


byte AttributeSet[256]=
{0x01,0x01,0x0A,0x0A,0x0F,0x0F,0x01,0x01,0x01,0x01,0x0F,0x0F,0x01,0x01,0x03,0x03
,0x01,0x01,0x0A,0x0A,0x0F,0x0F,0x01,0x01,0x01,0x01,0x0C,0x0C,0x01,0x01,0x03,0x03
,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
,0x0F,0x0F,0x08,0x08,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03
,0x0C,0x0C,0x0A,0x0A,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03
,0x03,0x03,0x04,0x06,0x0E,0x0E,0x08,0x08,0x0D,0x05,0x08,0x08,0x02,0x08,0x08,0x0F
,0x03,0x03,0x06,0x04,0x0E,0x0E,0x09,0x09,0x05,0x0D,0x09,0x09,0x08,0x02,0x09,0x09
,0x08,0x08,0x0F,0x0C,0x0C,0x0C,0x0C,0x0C,0x0D,0x0D,0x0F,0x0B,0x0B,0x0B,0x0F,0x0F
,0x08,0x08,0x0A,0x0C,0x0B,0x0B,0x0B,0x0C,0x05,0x05,0x0C,0x0B,0x0B,0x0B,0x0C,0x0C
,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x03,0x03
,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03
,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03};

void SetCharacterSet()
{
  //CopyMemory((int)&CharRam[0], &CharacterSet[0], 2048);
  CopyMemory((int)&CharRam[0], 0xc800, 2048);
}