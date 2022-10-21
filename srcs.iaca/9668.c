#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int in_bps, int ch, uint8_t ** out, const uint8_t * in, int is,
    int len, int channels)
{
  for (ch = 0; ch < channels; ch++)
     { IACA_START
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
      uint8_t *end = po + os * len;
      do
	{
	  *(int32_t *) po = *(const int32_t *) pi;
	  pi += is;
	  po += os;
	}
      while (po < end);
     } IACA_END
}
