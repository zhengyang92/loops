#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int stride, int y, uint8_t * tmp, uint8_t * data)
{
  for (y = 0; y < 4; y++)
    {
      memset (tmp, data[0], 4);
      tmp += stride;
    }
}
