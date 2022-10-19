#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;
typedef __uint8_t uint8_t;

int
fn (uint8_t * cur1, int x, uint8_t * dst1, int x0, const uint8_t * obmc1,
    const IDWTELEM * pred1, int x1)
{
  for (x = x0; x < x1; x++)
    {
      int v = (cur1[x] * obmc1[x] + (1 << (8 - 4 - 1))) >> (8 - 4);
      v = (v + pred1[x]) >> 4;
      if (v & (~255))
	v = ~(v >> 31);
      dst1[x] = v;
    }
}
