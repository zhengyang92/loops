#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned int uint32;

int
fn (tmsize_t i, uint32 * wp, tmsize_t stride)
{
  IACA_START for (i = stride - 4; i > 0; i--)
    {
      wp[stride] += wp[0];
      wp++;
     } IACA_END
}
