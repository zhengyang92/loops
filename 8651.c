#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * tmp, uint32_t mask, uint8_t * data)
{
  for (x = 0; x < 4; x++)
    {
      tmp[x] = data[mask & 3];
      mask >>= 2;
    }
}
