#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int *rseed, int gain, int i, int16_t * out)
{
  for (i = 0; i < (60 << 2); i++)
    {
      *rseed = *rseed * 521 + 259;
      out[i] = gain * *rseed >> 15;
    }
}
