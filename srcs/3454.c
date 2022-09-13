#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * srcU, int k, uint8_t * srcV, uint8_t * lut1)
{
  for (i = 0; i < k; i++)
    {
      srcU[i] = lut1[srcU[i]];
      srcV[i] = lut1[srcV[i]];
    }
}
