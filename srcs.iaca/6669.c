#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, int maskcolor, const uint8_t * mask, const uint8_t * srcv,
    const uint8_t * srcu, int use_mask, int k, int gray, int j, uint8_t * dst,
    const uint8_t * srcy)
{
  for (i = 0, j = 0, k = 0; i < w; j += (i & 1), i++, k += 3)
    {
      if (!use_mask || mask[i] == maskcolor)
	{
	  if (gray)
	    {
	      dst[k] = dst[k + 1] = dst[k + 2] = 0x80;
	    }
	  else
	    {
	      int y = srcy[i];
	      int u = srcu[j] - 128;
	      int v = srcv[j] - 128;
	      dst[k] = av_clip_uint8_c (y + (91881 * v + 32768 >> 16));
	      dst[k + 1] =
		av_clip_uint8_c (y + (-22554 * u - 46802 * v + 32768 >> 16));
	      dst[k + 2] = av_clip_uint8_c (y + (116130 * u + 32768 >> 16));
	}}
}}
