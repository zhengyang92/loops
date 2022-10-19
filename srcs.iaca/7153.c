#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int os, int ch, int out_bps, int is, const uint8_t ** in, int len,
    int channels, uint8_t * out)
{
  for (ch = 0; ch < channels; ch++)
    {
      const uint8_t *pi = in[ch];
      uint8_t *po = out + ch * out_bps;
      uint8_t *end = po + os * len;
      do
	{
	  *(uint8_t *) po =
	    av_clip_uint8_c (lrintf (*(const float *) pi * (1 << 7)) + 0x80);
	  pi += is;
	  po += os;
	}
      while (po < end);
    }
}
