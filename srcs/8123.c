#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const unsigned int color, int y, ptrdiff_t stride, int x, int b_w,
    uint8_t * dst)
{
  for (x = 0; x < b_w; x++)
    {
      dst[x + y * stride] = color;
    }
}
