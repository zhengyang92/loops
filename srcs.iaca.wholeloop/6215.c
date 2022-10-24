#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int V, int H, int a, const uint8_t * cm, int j, uint8_t * src, int stride)
{
  IACA_START for (j = 8; j > 0; --j)
    {
      int b = a;
      a += V;
      src[0] = cm[(b) >> 5];
      src[1] = cm[(b + H) >> 5];
      src[2] = cm[(b + 2 * H) >> 5];
      src[3] = cm[(b + 3 * H) >> 5];
      src[4] = cm[(b + 4 * H) >> 5];
      src[5] = cm[(b + 5 * H) >> 5];
      src[6] = cm[(b + 6 * H) >> 5];
      src[7] = cm[(b + 7 * H) >> 5];
      src += stride;
}IACA_END}
