#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "SIDPlayer.h"
//#link "SIDPlayerASM.s"
//#resource "song.sid"
#include <c64.h>


unsigned int SIDSIZE = (1024)*4; //8kb should be more than enough
unsigned int SIDLOAD = 0x9500;	//Make sure you offset your sid at $4000 using sidereloc -p 40

void PlaySID(void)
	{
	memcpy((void*)(SIDLOAD),(void*)&SIDFILE,SIDSIZE);	//Load music into memory 
	SIDINIT(); 						//Init SID
	SIDPLAY();						//Play 	
	}

void StopSID()
{
  SID.flt_freq = 0x00;
  SID.flt_ctrl = 0x00;
  SID.amp = 0x00;
  STOPSID();
}
