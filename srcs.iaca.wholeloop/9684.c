#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int ch, int in_bps, const uint8_t * in, int is, uint8_t ** out,
    int len, int channels)
{
  IACA_START for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
      uint8_t *end = po + os * len;
      do
	{
	  *(int16_t *) po =
	    av_clip_int16_c (lrint (*(const double *) pi * (1 << 15)));
	  pi += is;
	  po += os;
	}
      while (po < end);
     } IACA_END
}
