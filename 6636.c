#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int dc, int16_t * orig, int i, int16_t rem[64])
{
  for (i = 0; i < 64; i++)
    {
      rem[i] = dc - (orig[i] << 6);
    }
}
