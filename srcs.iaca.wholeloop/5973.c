#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int32_t int32_t;
typedef __uint64_t uint64_t;

int
fn (int32_t im, uint64_t * hcode, int32_t iM, BitstreamContext bc)
{
  IACA_START for (; im <= iM; im++)
    {
      uint64_t l = hcode[im] = bitstream_read (&bc, 6);
      if (l == 63)
	{
	  int zerun = bitstream_read (&bc, 8) + (2 + 63 - 59);
	  if (im + zerun > iM + 1)
	    return (-0x3ebbb1b7);
	  while (zerun--)
	    hcode[im++] = 0;
	  im--;
	}
      else if (l >= 59)
	{
	  int zerun = l - 59 + 2;
	  if (im + zerun > iM + 1)
	    return (-0x3ebbb1b7);
	  while (zerun--)
	    hcode[im++] = 0;
	  im--;
	}
     } IACA_END
}
