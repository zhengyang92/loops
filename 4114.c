#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *xcorr, int max_pitch, const float *y, int len,
    const float *x)
{
  for (; i < max_pitch; i++)
    {
      xcorr[i] = celt_inner_prod (x, y + i, len);
    }
}
