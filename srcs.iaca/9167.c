#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int stride, int y, uint8_t * tmp, uint32_t mask, int i, int d, int x,
    int k, uint8_t * tmp2, uint8_t * mv, uint8_t * ref, int d2,
    uint8_t * data)
{
  for (k = 0; k < 4; k++)
     { IACA_START
      d = ((k & 1) << 1) + ((k & 2) * stride);
      d2 = ((k & 1) << 1) + ((k & 2) * stride);
      tmp2 = ref + i + d2;
      switch (mask & 0xC0)
	{
	case 0x80:
	  x = (*mv) >> 4;
	  if (x & 8)
	    x = 8 - x;
	  y = (*mv++) & 0xF;
	  if (y & 8)
	    y = 8 - y;
	  tmp2 += x + y * stride;
	case 0x00:
	  tmp[d + 0] = tmp2[0];
	  tmp[d + 1] = tmp2[1];
	  tmp[d + 0 + stride] = tmp2[0 + stride];
	  tmp[d + 1 + stride] = tmp2[1 + stride];
	  break;
	case 0x40:
	  tmp[d + 0] = data[0];
	  tmp[d + 1] = data[0];
	  tmp[d + 0 + stride] = data[0];
	  tmp[d + 1 + stride] = data[0];
	  data++;
	  break;
	case 0xC0:
	  tmp[d + 0] = *data++;
	  tmp[d + 1] = *data++;
	  tmp[d + 0 + stride] = *data++;
	  tmp[d + 1 + stride] = *data++;
	  break;
	}
      mask <<= 2;
     } IACA_END
}
