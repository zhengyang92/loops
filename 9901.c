#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int DC, int j, uint8_t * dst, int i)
{
  for (i = 0; i < 4; ++i)
    {
      dst[(i) + (j) * 32] = clip_8b (dst[(i) + (j) * 32] + ((DC) >> 3));
    }
}
