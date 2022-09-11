#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src2, int x, int b_w, uint8_t * dst, int a,
    const uint8_t * src1, int b)
{
  for (x = 0; x < b_w; x++)
    {
      dst[x] = (a * src1[x] + b * src2[x] + 4) >> 3;
    }
}
