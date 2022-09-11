#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int radius, const uint16_t * filter, int k, const uint8_t * src,
    int filt_w, ptrdiff_t src_stride, int j)
{
  int sum = 0;
  for (k = 0; k < filt_w; k++)
    {
      sum += filter[k] * src[(i - radius + k) * src_stride + j];
    }
}
