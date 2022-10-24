#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int left_samples_available, const uint8_t scan8[51], int i, void *logctx,
    const int8_t left[12], const int mask[4], int8_t * pred_mode_cache)
{
  IACA_START for (i = 0; i < 4; i++)
    if (!(left_samples_available & mask[i]))
      {
	int status = left[pred_mode_cache[scan8[0] + 8 * i]];
	if (status < 0)
	  {
	    av_log (logctx, 16,
		    "left block unavailable for requested intra4x4 mode %d\n",
		    status);
	    return (-0x3ebbb1b7);
	  }
	else if (status)
	  {
	    pred_mode_cache[scan8[0] + 8 * i] = status;
	  }
      }
  IACA_END
}
