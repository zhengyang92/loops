#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int w, int i, IDWTELEM * ref, IDWTELEM * dst, int add, int shift, int mul,
    IDWTELEM * src)
{
  for (; i < w; i++)
    {
      dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
}
