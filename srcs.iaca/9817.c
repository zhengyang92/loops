#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned int uint32;

int
fn (uint32 * tp, unsigned char *bp, tmsize_t npixels, tmsize_t i, tmsize_t cc)
{
  for (i = 0; i < npixels && cc >= 3; i++)
     { IACA_START
      tp[i] = bp[0] << 16 | bp[1] << 8 | bp[2];
      bp += 3;
      cc -= 3;
     } IACA_END
}
