#include <peekpoke.h>
#include "Common.h"

char str[16];

byte ReadBit(byte byteToRead, char bit)
{
    bit = 1 << bit;
    return(bit & byteToRead);
}
void WriteBit(byte *byteToSet, char bit, bool value)
{
  if (value)
  {
    bit = 1 << bit;
  }
  else
  {
    bit = 0 << bit;
  }
  *byteToSet = *byteToSet | bit;
}

bool CheckBit(byte source, byte position)
{
  return (source & (1<<position));
}

bool raster_check(byte line)
{
  if(VIC.rasterline == line)
     return true;
     else
     return false;
}