#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t * ptr, int i, ptrdiff_t stride, int sum_p1p0, int step,
    int sum_q1q0, uint8_t * src)
{
  for (i = 0, ptr = src; i < 4; i++, ptr += stride)
    {
      sum_p1p0 += ptr[-2 * step] - ptr[-1 * step];
      sum_q1q0 += ptr[1 * step] - ptr[0 * step];
    }
}
