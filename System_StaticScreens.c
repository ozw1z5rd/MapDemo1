//#include <c64.h>
#include <peekpoke.h>
#include "common.h"

int screenRam = 0xC800;
int colorRam = 0xD800;

unsigned char StaticScreen[2][1000]={
{
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,233,160,160,160,160,160,160,168,160,160,160,160,169,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,223,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,8,5,12,12,15,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,160,160,160,160,160,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,160,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,160,160,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,95,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,32,32,32,160,160,160,160,160,160,160,160,160,160,160,160,32,32,160,32,
32,32,32,32,160,160,160,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,160,160,160,160,160,160,160,160,160,160,160,160,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,95,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,105,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
},
  {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,233,160,160,160,160,160,168,160,160,160,169,160,160,160,160,160,223,32,32,233,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,223,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,8,5,12,12,15,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,95,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,105,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,160,160,160,160,160,160,160,160,160,160,160,160,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,160,160,160,160,160,160,160,160,160,160,160,160,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,160,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,95,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,105,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
  }
};

unsigned char StaticColor[2][1000]={
{
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,
14,3,14,14,14,14,14,14,14,3,3,3,3,3,14,3,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,3,3,3,3,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,0,14,14,3,14,14,3,3,3,3,3,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,0,3,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,0,0,14,14,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,3,3,3,3,3,3,3,3,14,14,14,14,14,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,0,0,0,0,0,14,14,14,14,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,0,14,14,14,14,14,14,14,14,14,14,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,0,0,14,14,14,14,14,14,14,14,14,14,0,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,14,14,2,2,2,2,2,2,2,2,2,2,2,2,14,14,3,14,
14,14,14,14,0,0,0,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,5,5,5,5,5,5,5,5,5,5,5,5,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14
},
{
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,
14,3,14,14,14,14,14,14,14,3,3,3,3,3,14,3,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,3,3,3,3,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,14,14,3,14,14,3,3,3,3,3,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,14,14,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,14,3,3,3,3,3,3,3,3,14,14,14,14,14,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,2,2,2,2,2,2,2,2,2,2,2,2,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,5,5,5,5,5,5,5,5,5,5,5,5,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,3,3,3,14,14,14,14,14,14,14,14,14,14,14,14,14,14
}
};


void SetScreen(byte index)
{
  int i;
  for (i = 0;i < 1000; i+=2)
  {
      POKEW(screenRam + i, PEEKW(&StaticScreen[index][i]));
      POKEW(colorRam + i, PEEKW(&StaticColor[index][i]));    
  }
}