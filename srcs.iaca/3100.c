#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * src, int is_alpha_plane, int box_width, int j, uint16_t * dst)
{
  for (j = 0; j < box_width; ++j)
    {
      if (!is_alpha_plane)
	{
	  dst[j] = src[j];
	}
      else
	{
	  dst[j] = src[j] << 6;
	}
    }
}
