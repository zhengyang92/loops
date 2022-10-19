#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, const uint8_t * b, const uint8_t * r, int len, uint32_t * out,
    const uint8_t * g, int step)
{
  int offset = 0;
  for (i = 0; i < len; ++i)
    {
      out[i] = MakeARGB32 (0xff, r[offset], g[offset], b[offset]);
      offset += step;
    }
}
