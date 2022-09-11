#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int i, ptrdiff_t stride, uint8_t * src, int sum_p1p2,
    int step)
{
  int sum_q1q2 = 0;
  for (i = 0, ptr = src; i < 4; i++, ptr += stride)
    {
      sum_p1p2 += ptr[-2 * step] - ptr[-3 * step];
      sum_q1q2 += ptr[1 * step] - ptr[2 * step];
    }
}
