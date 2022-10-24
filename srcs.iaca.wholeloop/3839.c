#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int dstStride2[4], int srcStride2[4], int i)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      srcStride2[i] *= -1;
      dstStride2[i] *= -1;
     } IACA_END
}
