#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * left, int i, uint16_t * top)
{
  for (i = 0; i < 2 * 32; i++)
    {
      left[i] = 128;
      top[i] = 128;
    }
}
