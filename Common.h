#ifndef _COMMON_H
#define _COMMON_H

#include <c64.h>
#include <stdint.h>
#include <string.h>
#include <peekpoke.h>

typedef uint8_t byte;
typedef uint16_t word;
typedef int8_t sbyte;
typedef enum { false, true } bool;
typedef enum { Title, Credits, EditParty, Map, Combat, Menu, SaveLoad } screenName;

extern char str[16];
extern int randseed;
extern 

#define COLS 40
#define ROWS 25

#define CopyMemory(dest, src, length)(memcpy((int*)dest, (int*)src, length))
void raster_wait(byte line);
void wait_vblank(byte frames);

#define ScreenDisable() (POKE(0xD011, PEEK(0xD011)&239))
#define ScreenEnable() (POKE(0xD011, PEEK(0xD011)|16))

void SwitchScreen(screenName screen);
void UpdateScreen(void);

void WriteBit(byte *byteToSet, char bit, bool value);
byte ReadBit(byte byteToRead, char bit);
bool CheckBit(byte source, byte position);
bool raster_check(byte line);

/*****************************************************************************/
/*                                                                           */
/*                        cbm_petscii_charmap.h                              */
/*                                                                           */
/*         CBM system standard string mapping (ISO-8859-1 -> PetSCII)        */
/*                                                                           */
/*                                                                           */
/* 2019-03-10, Greg King                                                     */
/*                                                                           */
/* This software is provided "as-is", without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated, but is not required.                                      */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice must not be removed or altered from any source             */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

/* No include guard here!  Multiple use in one file might be intentional. */

#pragma warn (remap-zero, push, off)

#pragma charmap (0x00, 0x00)
#pragma charmap (0x01, 0x01)
#pragma charmap (0x02, 0x02)
#pragma charmap (0x03, 0x03)
#pragma charmap (0x04, 0x04)
#pragma charmap (0x05, 0x05)
#pragma charmap (0x06, 0x06)
#pragma charmap (0x07, 0x07)
#pragma charmap (0x08, 0x14)
#pragma charmap (0x09, 0x09)
#pragma charmap (0x0A, 0x0D)
#pragma charmap (0x0B, 0x11)
#pragma charmap (0x0C, 0x93)
#pragma charmap (0x0D, 0x0A)
#pragma charmap (0x0E, 0x0E)
#pragma charmap (0x0F, 0x0F)
#pragma charmap (0x10, 0x10)
#pragma charmap (0x11, 0x0B)
#pragma charmap (0x12, 0x12)
#pragma charmap (0x13, 0x13)
#pragma charmap (0x14, 0x08)
#pragma charmap (0x15, 0x15)
#pragma charmap (0x16, 0x16)
#pragma charmap (0x17, 0x17)
#pragma charmap (0x18, 0x18)
#pragma charmap (0x19, 0x19)
#pragma charmap (0x1A, 0x1A)
#pragma charmap (0x1B, 0x1B)
#pragma charmap (0x1C, 0x1C)
#pragma charmap (0x1D, 0x1D)
#pragma charmap (0x1E, 0x1E)
#pragma charmap (0x1F, 0x1F)

#pragma charmap (0x20, 0x20)
#pragma charmap (0x21, 0x21)
#pragma charmap (0x22, 0x22)
#pragma charmap (0x23, 0x23)
#pragma charmap (0x24, 0x24)
#pragma charmap (0x25, 0x25)
#pragma charmap (0x26, 0x26)
#pragma charmap (0x27, 0x27)
#pragma charmap (0x28, 0x28)
#pragma charmap (0x29, 0x29)
#pragma charmap (0x2A, 0x2A)
#pragma charmap (0x2B, 0x2B)
#pragma charmap (0x2C, 0x2C)
#pragma charmap (0x2D, 0x2D)
#pragma charmap (0x2E, 0x2E)
#pragma charmap (0x2F, 0x2F)
#pragma charmap (0x30, 0x30)
#pragma charmap (0x31, 0x31)
#pragma charmap (0x32, 0x32)
#pragma charmap (0x33, 0x33)
#pragma charmap (0x34, 0x34)
#pragma charmap (0x35, 0x35)
#pragma charmap (0x36, 0x36)
#pragma charmap (0x37, 0x37)
#pragma charmap (0x38, 0x38)
#pragma charmap (0x39, 0x39)
#pragma charmap (0x3A, 0x3A)
#pragma charmap (0x3B, 0x3B)
#pragma charmap (0x3C, 0x3C)
#pragma charmap (0x3D, 0x3D)
#pragma charmap (0x3E, 0x3E)
#pragma charmap (0x3F, 0x3F)

#pragma charmap (0x40, 0x40)
#pragma charmap (0x41, 0xC1)
#pragma charmap (0x42, 0xC2)
#pragma charmap (0x43, 0xC3)
#pragma charmap (0x44, 0xC4)
#pragma charmap (0x45, 0xC5)
#pragma charmap (0x46, 0xC6)
#pragma charmap (0x47, 0xC7)
#pragma charmap (0x48, 0xC8)
#pragma charmap (0x49, 0xC9)
#pragma charmap (0x4A, 0xCA)
#pragma charmap (0x4B, 0xCB)
#pragma charmap (0x4C, 0xCC)
#pragma charmap (0x4D, 0xCD)
#pragma charmap (0x4E, 0xCE)
#pragma charmap (0x4F, 0xCF)
#pragma charmap (0x50, 0xD0)
#pragma charmap (0x51, 0xD1)
#pragma charmap (0x52, 0xD2)
#pragma charmap (0x53, 0xD3)
#pragma charmap (0x54, 0xD4)
#pragma charmap (0x55, 0xD5)
#pragma charmap (0x56, 0xD6)
#pragma charmap (0x57, 0xD7)
#pragma charmap (0x58, 0xD8)
#pragma charmap (0x59, 0xD9)
#pragma charmap (0x5A, 0xDA)
#pragma charmap (0x5B, 0x5B)
#pragma charmap (0x5C, 0xBF)
#pragma charmap (0x5D, 0x5D)
#pragma charmap (0x5E, 0x5E)
#pragma charmap (0x5F, 0xA4)

#pragma charmap (0x60, 0xAD)
#pragma charmap (0x61, 0x41)
#pragma charmap (0x62, 0x42)
#pragma charmap (0x63, 0x43)
#pragma charmap (0x64, 0x44)
#pragma charmap (0x65, 0x45)
#pragma charmap (0x66, 0x46)
#pragma charmap (0x67, 0x47)
#pragma charmap (0x68, 0x48)
#pragma charmap (0x69, 0x49)
#pragma charmap (0x6A, 0x4A)
#pragma charmap (0x6B, 0x4B)
#pragma charmap (0x6C, 0x4C)
#pragma charmap (0x6D, 0x4D)
#pragma charmap (0x6E, 0x4E)
#pragma charmap (0x6F, 0x4F)
#pragma charmap (0x70, 0x50)
#pragma charmap (0x71, 0x51)
#pragma charmap (0x72, 0x52)
#pragma charmap (0x73, 0x53)
#pragma charmap (0x74, 0x54)
#pragma charmap (0x75, 0x55)
#pragma charmap (0x76, 0x56)
#pragma charmap (0x77, 0x57)
#pragma charmap (0x78, 0x58)
#pragma charmap (0x79, 0x59)
#pragma charmap (0x7A, 0x5A)
#pragma charmap (0x7B, 0xB3)
#pragma charmap (0x7C, 0xDD)
#pragma charmap (0x7D, 0xAB)
#pragma charmap (0x7E, 0xB1)
#pragma charmap (0x7F, 0xDF)

#pragma charmap (0x80, 0x80)
#pragma charmap (0x81, 0x81)
#pragma charmap (0x82, 0x82)
#pragma charmap (0x83, 0x83)
#pragma charmap (0x84, 0x84)
#pragma charmap (0x85, 0x85)
#pragma charmap (0x86, 0x86)
#pragma charmap (0x87, 0x87)
#pragma charmap (0x88, 0x88)
#pragma charmap (0x89, 0x89)
#pragma charmap (0x8A, 0x8A)
#pragma charmap (0x8B, 0x8B)
#pragma charmap (0x8C, 0x8C)
#pragma charmap (0x8D, 0x8D)
#pragma charmap (0x8E, 0x8E)
#pragma charmap (0x8F, 0x8F)
#pragma charmap (0x90, 0x90)
#pragma charmap (0x91, 0x91)
#pragma charmap (0x92, 0x92)
#pragma charmap (0x93, 0x0C)
#pragma charmap (0x94, 0x94)
#pragma charmap (0x95, 0x95)
#pragma charmap (0x96, 0x96)
#pragma charmap (0x97, 0x97)
#pragma charmap (0x98, 0x98)
#pragma charmap (0x99, 0x99)
#pragma charmap (0x9A, 0x9A)
#pragma charmap (0x9B, 0x9B)
#pragma charmap (0x9C, 0x9C)
#pragma charmap (0x9D, 0x9D)
#pragma charmap (0x9E, 0x9E)
#pragma charmap (0x9F, 0x9F)

#pragma charmap (0xA0, 0xA0)
#pragma charmap (0xA1, 0xA1)
#pragma charmap (0xA2, 0xA2)
#pragma charmap (0xA3, 0xA3)
#pragma charmap (0xA4, 0xA4)
#pragma charmap (0xA5, 0xA5)
#pragma charmap (0xA6, 0xA6)
#pragma charmap (0xA7, 0xA7)
#pragma charmap (0xA8, 0xA8)
#pragma charmap (0xA9, 0xA9)
#pragma charmap (0xAA, 0xAA)
#pragma charmap (0xAB, 0xAB)
#pragma charmap (0xAC, 0xAC)
#pragma charmap (0xAD, 0xAD)
#pragma charmap (0xAE, 0xAE)
#pragma charmap (0xAF, 0xAF)
#pragma charmap (0xB0, 0xB0)
#pragma charmap (0xB1, 0xB1)
#pragma charmap (0xB2, 0xB2)
#pragma charmap (0xB3, 0xB3)
#pragma charmap (0xB4, 0xB4)
#pragma charmap (0xB5, 0xB5)
#pragma charmap (0xB6, 0xB6)
#pragma charmap (0xB7, 0xB7)
#pragma charmap (0xB8, 0xB8)
#pragma charmap (0xB9, 0xB9)
#pragma charmap (0xBA, 0xBA)
#pragma charmap (0xBB, 0xBB)
#pragma charmap (0xBC, 0xBC)
#pragma charmap (0xBD, 0xBD)
#pragma charmap (0xBE, 0xBE)
#pragma charmap (0xBF, 0xBF)

#pragma charmap (0xC0, 0x60)
#pragma charmap (0xC1, 0x61)
#pragma charmap (0xC2, 0x62)
#pragma charmap (0xC3, 0x63)
#pragma charmap (0xC4, 0x64)
#pragma charmap (0xC5, 0x65)
#pragma charmap (0xC6, 0x66)
#pragma charmap (0xC7, 0x67)
#pragma charmap (0xC8, 0x68)
#pragma charmap (0xC9, 0x69)
#pragma charmap (0xCA, 0x6A)
#pragma charmap (0xCB, 0x6B)
#pragma charmap (0xCC, 0x6C)
#pragma charmap (0xCD, 0x6D)
#pragma charmap (0xCE, 0x6E)
#pragma charmap (0xCF, 0x6F)
#pragma charmap (0xD0, 0x70)
#pragma charmap (0xD1, 0x71)
#pragma charmap (0xD2, 0x72)
#pragma charmap (0xD3, 0x73)
#pragma charmap (0xD4, 0x74)
#pragma charmap (0xD5, 0x75)
#pragma charmap (0xD6, 0x76)
#pragma charmap (0xD7, 0x77)
#pragma charmap (0xD8, 0x78)
#pragma charmap (0xD9, 0x79)
#pragma charmap (0xDA, 0x7A)
#pragma charmap (0xDB, 0x7B)
#pragma charmap (0xDC, 0x7C)
#pragma charmap (0xDD, 0x7D)
#pragma charmap (0xDE, 0x7E)
#pragma charmap (0xDF, 0x7F)

#pragma charmap (0xE0, 0xE0)
#pragma charmap (0xE1, 0xE1)
#pragma charmap (0xE2, 0xE2)
#pragma charmap (0xE3, 0xE3)
#pragma charmap (0xE4, 0xE4)
#pragma charmap (0xE5, 0xE5)
#pragma charmap (0xE6, 0xE6)
#pragma charmap (0xE7, 0xE7)
#pragma charmap (0xE8, 0xE8)
#pragma charmap (0xE9, 0xE9)
#pragma charmap (0xEA, 0xEA)
#pragma charmap (0xEB, 0xEB)
#pragma charmap (0xEC, 0xEC)
#pragma charmap (0xED, 0xED)
#pragma charmap (0xEE, 0xEE)
#pragma charmap (0xEF, 0xEF)
#pragma charmap (0xF0, 0xF0)
#pragma charmap (0xF1, 0xF1)
#pragma charmap (0xF2, 0xF2)
#pragma charmap (0xF3, 0xF3)
#pragma charmap (0xF4, 0xF4)
#pragma charmap (0xF5, 0xF5)
#pragma charmap (0xF6, 0xF6)
#pragma charmap (0xF7, 0xF7)
#pragma charmap (0xF8, 0xF8)
#pragma charmap (0xF9, 0xF9)
#pragma charmap (0xFA, 0xFA)
#pragma charmap (0xFB, 0xFB)
#pragma charmap (0xFC, 0xFC)
#pragma charmap (0xFD, 0xFD)
#pragma charmap (0xFE, 0xFE)
#pragma charmap (0xFF, 0xFF)

#pragma warn (remap-zero, pop)

#endif