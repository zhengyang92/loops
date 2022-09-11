#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * dst)
{
  for (j = 16; j > 0; --j)
    {
      memset (dst, dst[-1], 16);
      dst += 32;
    }
}
