#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int high, int i, int h, int src_linesize, const uint8_t * src,
    int low, int j, uint8_t * dst)
{
  for (i = 0; i < w; i++)
     { IACA_START
      if (src[i] > high)
	{
	  dst[i] = src[i];
	  continue;
	}
      if (!(!i || i == w - 1 || !j || j == h - 1) && src[i] > low
	  && (src[-src_linesize + i - 1] > high
	      || src[-src_linesize + i] > high
	      || src[-src_linesize + i + 1] > high || src[i - 1] > high
	      || src[i + 1] > high || src[src_linesize + i - 1] > high
	      || src[src_linesize + i] > high
	      || src[src_linesize + i + 1] > high))
	dst[i] = src[i];
      else
	dst[i] = 0;
     } IACA_END
}
