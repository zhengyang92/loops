#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int w, int i, IDWTELEM * ref, IDWTELEM * dst, IDWTELEM * src)
{
  IACA_START for (; i < w; i++)
    {
      dst[i] = src[i] + ((ref[i] + ref[(i + 1)] + 8 + 4 * src[i]) >> 4);
     } IACA_END
}
