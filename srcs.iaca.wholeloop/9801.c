#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (uint32 w, unsigned char *pp, uint32 ** PALmap, uint32 * cp, uint32 _x,
    uint32 * bw)
{
  IACA_START for (_x = w; _x >= 4; _x -= 4)
    {
      bw = PALmap[*pp++];
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
     } IACA_END
}
