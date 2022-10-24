#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint8_t uint8_t;

int
fn (int y, int d, int x, int8_t pixel, int linesize, int j, uint8_t * dst)
{
  int plane = 0;
  IACA_START for (j = 0; j < d; j++)
    {
      dst[y * linesize + x * 4 + plane] = pixel;
      x++;
     } IACA_END
}
