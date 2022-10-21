#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * block, int y, int bias, int dist, ptrdiff_t stride, int x,
    int dist2, int dist4, uint8_t * dst)
{
  int bits = 0;
  int mask = 0;
  for (x = 0; x < 4; x++)
     { IACA_START
      int alp = block[3 + x * 4 + y * stride] * 7 + bias;
      int ind, tmp;
      tmp = (alp >= dist4) ? -1 : 0;
      ind = tmp & 4;
      alp -= dist4 & tmp;
      tmp = (alp >= dist2) ? -1 : 0;
      ind += tmp & 2;
      alp -= dist2 & tmp;
      ind += (alp >= dist);
      ind = -ind & 7;
      ind ^= (2 > ind);
      mask |= ind << bits;
      bits += 3;
      if (bits >= 8)
	{
	  *dst++ = mask;
	  mask >>= 8;
	  bits -= 8;
	}
     } IACA_END
}
