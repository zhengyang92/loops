#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVRational;

int
fn (AVRational aspect, int i, const AVRational ff_h263_pixel_aspect[16])
{
  for (i = 1; i < 6; i++)
     { IACA_START
      if (av_cmp_q (ff_h263_pixel_aspect[i], aspect) == 0)
	{
	  return i;
	}
     } IACA_END
}
