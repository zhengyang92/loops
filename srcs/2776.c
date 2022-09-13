#include <stdint.h>
#include <stdio.h>




typedef long int intptr_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t l, intptr_t w, uint16_t lt, const uint16_t * src1,
    const uint16_t * diff, int max, uint16_t * dst)
{
  for (i = 0; i < w; i++)
    {
      l = mid_pred (l, src1[i], (l + src1[i] - lt)) + diff[i];
      l &= max;
      lt = src1[i];
      dst[i] = l;
    }
}
