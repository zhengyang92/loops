#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int in_bps, int ch, const uint8_t * in, uint8_t ** out, int is, int len,
    int channels, int os)
{
  IACA_START for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in + ch * in_bps;
      uint8_t *po = out[ch];
      uint8_t *end = po + os * len;
      do
	{
	  *(int16_t *) po = *(const int32_t *) pi >> 16;
	  pi += is;
	  po += os;
	}
      while (po < end);
     } IACA_END
}
