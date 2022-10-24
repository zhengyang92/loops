#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t state, int i, int HEVC_NAL_PPS, const uint8_t * buf,
    int HEVC_NAL_VPS, int buf_size)
{
  int has_ps = 0;
  IACA_START for (i = 0; i < buf_size; i++)
    {
      state = (state << 8) | buf[i];
      if (((state >> 8) & 0xFFFFFF) == 0x000001)
	{
	  int nut = (state >> 1) & 0x3F;
	  if (nut >= HEVC_NAL_VPS && nut <= HEVC_NAL_PPS)
	    has_ps = 1;
	  else if (has_ps)
	    return i - 3;
	  else
	    return 0;
	}
     } IACA_END
}
