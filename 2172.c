#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint8_t uint8_t;

int
fn (int left_samples_available, const uint8_t scan8[51], int i, void *logctx,
    const int8_t left[12], const int mask[4], int8_t * pred_mode_cache)
{
  for (i = 0; i < 4; i++)
    if (!(left_samples_available & mask[i]))
      {
	int status = left[pred_mode_cache[scan8[0] + 8 * i]];
	if (status < 0)
	  {
	    av_log (logctx, 16,
		    "left block unavailable for requested intra4x4 mode %d\n",
		    status);
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  }
	else if (status)
	  {
	    pred_mode_cache[scan8[0] + 8 * i] = status;
	  }
      }
}
