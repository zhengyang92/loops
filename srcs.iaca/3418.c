#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int tblk[16], int i, int stride)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      dst[0] =
	((5 * ((tblk[i * 4 + 0]) + (tblk[i * 4 + 1]) + (tblk[i * 4 + 2])) +
	  2 * (tblk[i * 4 + 3])) + 0x20) >> 6;
      dst[1] =
	((5 * ((tblk[i * 4 + 0]) - (tblk[i * 4 + 2]) - (tblk[i * 4 + 3])) +
	  2 * (tblk[i * 4 + 1])) + 0x20) >> 6;
      dst[2] =
	((5 * ((tblk[i * 4 + 0]) - (tblk[i * 4 + 2]) + (tblk[i * 4 + 3])) -
	  2 * (tblk[i * 4 + 1])) + 0x20) >> 6;
      dst[3] =
	((5 * ((tblk[i * 4 + 0]) - (tblk[i * 4 + 1]) + (tblk[i * 4 + 2])) -
	  2 * (tblk[i * 4 + 3])) + 0x20) >> 6;;
      dst += stride;
     } IACA_END
}
