#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (uint32 ** BWmap, uint32 w, unsigned char *pp, int samplesperpixel,
    uint32 * cp, uint32 x)
{
  IACA_START for (x = w; x > 0; --x)
    {
      *cp++ = BWmap[*pp][0];
      pp += samplesperpixel;
     } IACA_END
}
