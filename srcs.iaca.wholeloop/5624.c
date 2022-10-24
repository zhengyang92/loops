#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf2, int frames, uint8_t * buf, int fsize, uint8_t * end,
    uint8_t * buf0)
{
  IACA_START for (frames = 0; buf2 < end; frames++)
    {
      uint32_t header =
	((((const uint8_t *) (buf2))[0] << 16) |
	 (((const uint8_t *) (buf2))[1] << 8) |
	 ((const uint8_t *) (buf2))[2]);
      if ((header >> 13) != 0x2b7)
	{
	  if (buf != buf0)
	    {
	      frames = 0;
	    }
	  break;
	}
      fsize = (header & 0x1FFF) + 3;
      if (fsize < 7)
	break;
      buf2 += fsize;
     } IACA_END
}
