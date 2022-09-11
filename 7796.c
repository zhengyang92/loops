#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * out, int *rseed, int i, int gain)
{
  for (i = 0; i < (60 << 2); i++)
    {
      *rseed = (int16_t) (*rseed * 521 + 259);
      out[i] = gain * *rseed >> 15;
    }
}
