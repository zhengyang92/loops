#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int ch, const uint8_t ** in, int out_bps, int is, int len, int channels,
    int os, uint8_t * out)
{
  for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in[ch];
      uint8_t *po = out + ch * out_bps;
      uint8_t *end = po + os * len;
      do
	{
	  *(uint8_t *) po =
	    av_clip_uint8_c (lrint (*(const double *) pi * (1 << 7)) + 0x80);
	  pi += is;
	  po += os;
	}
      while (po < end);
    }
}
