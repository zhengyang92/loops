#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int ch, int in_bps, const uint8_t * in, int is, uint8_t ** out,
    int len, int channels)
{
  for (ch = 0; ch < channels; ch++)
     { IACA_START
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
      uint8_t *end = po + os * len;
      do
	{
	  *(uint8_t *) po =
	    av_clip_uint8_c (lrint (*(const double *) pi * (1 << 7)) + 0x80);
	  pi += is;
	  po += os;
	}
      while (po < end);
     } IACA_END
}
