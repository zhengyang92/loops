#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int16_t * fir, int *iir, int i)
{
  for (i = 0; i < (60 << 2); i++)
     { IACA_START
      *iir =
	(buf[i] << 15) + ((-*fir) << 15) + ((((*iir) >> 16) * (0x7f00) * 2) +
					    (((*iir) & 0xffff) *
					     (0x7f00) >> 15));
      *fir = buf[i];
      buf[i] = av_clipl_int32_c ((int64_t) * iir + (1 << 15)) >> 16;
     } IACA_END
}
