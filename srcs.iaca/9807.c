#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (uint32 ** BWmap, uint32 w, unsigned char *pp, uint32 _x, uint32 * cp,
    uint32 * bw)
{
  for (_x = w; _x >= 4; _x -= 4)
    {
      bw = BWmap[*pp++];
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
    }
}
