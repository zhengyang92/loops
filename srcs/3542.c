#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int n, uint16_t * dst, int len, int val)
{
  for (n = 0; n < len; n++)
    {
      dst[n] = val;
    }
}
