#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint16_t uint16_t;

int
fn (int i, int64_t * sum, const uint16_t * src1, int be, int len,
    int64_t * sum2)
{
  IACA_START for (i = 0; i < len / 2; i++)
    {
      if ((0 && !be) || (!0 && be))
	{
	  *sum += av_bswap16 (src1[i]);
	  *sum2 +=
	    (uint32_t) av_bswap16 (src1[i]) * (uint32_t) av_bswap16 (src1[i]);
	}
      else
	{
	  *sum += src1[i];
	  *sum2 += (uint32_t) src1[i] * (uint32_t) src1[i];
	}
     } IACA_END
}
