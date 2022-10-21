#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, uint8_t * cmkpnn, const int cmk_linesizeUV, const int width,
    uint8_t * cmkp, uint8_t * cmkpp, uint8_t * cmkpU, uint8_t * cmkpV,
    uint8_t * cmkpn)
{
  for (x = 1; x < width - 1; x++)
     { IACA_START
      if ((cmkpV[x] == 0xff
	   && (cmkpV[(x) - 1 - (cmk_linesizeUV)] == 0xff
	       || cmkpV[(x) - (cmk_linesizeUV)] == 0xff
	       || cmkpV[(x) + 1 - (cmk_linesizeUV)] == 0xff
	       || cmkpV[(x) - 1] == 0xff || cmkpV[(x) + 1] == 0xff
	       || cmkpV[(x) - 1 + (cmk_linesizeUV)] == 0xff
	       || cmkpV[(x) + (cmk_linesizeUV)] == 0xff
	       || cmkpV[(x) + 1 + (cmk_linesizeUV)] == 0xff))
	  || (cmkpU[x] == 0xff
	      && (cmkpU[(x) - 1 - (cmk_linesizeUV)] == 0xff
		  || cmkpU[(x) - (cmk_linesizeUV)] == 0xff
		  || cmkpU[(x) + 1 - (cmk_linesizeUV)] == 0xff
		  || cmkpU[(x) - 1] == 0xff || cmkpU[(x) + 1] == 0xff
		  || cmkpU[(x) - 1 + (cmk_linesizeUV)] == 0xff
		  || cmkpU[(x) + (cmk_linesizeUV)] == 0xff
		  || cmkpU[(x) + 1 + (cmk_linesizeUV)] == 0xff)))
	{
	  ((uint16_t *) cmkp)[x] = 0xffff;
	  ((uint16_t *) cmkpn)[x] = 0xffff;
	  if (y & 1)
	    ((uint16_t *) cmkpp)[x] = 0xffff;
	  else
	    ((uint16_t *) cmkpnn)[x] = 0xffff;
	}
     } IACA_END
}
