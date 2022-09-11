#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, uint8_t * diff, uint8_t * dst, uint8_t lt, uint8_t * src1,
    uint8_t l)
{
  for (i = 0; i < w; i++)
    {
      l = mid_pred (l, src1[i], l + src1[i] - lt) + diff[i];
      lt = src1[i];
      dst[i] = l;
    }
}
