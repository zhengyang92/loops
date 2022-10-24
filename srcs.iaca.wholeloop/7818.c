#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (const uint8_t scan8[51], int i, const int8_t top[12], void *logctx,
    int8_t * pred_mode_cache)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      int status = top[pred_mode_cache[scan8[0] + i]];
      if (status < 0)
	{
	  av_log (logctx, 16,
		  "top block unavailable for requested intra mode %d\n",
		  status);
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
	}
      else if (status)
	{
	  pred_mode_cache[scan8[0] + i] = status;
	}
     } IACA_END
}
