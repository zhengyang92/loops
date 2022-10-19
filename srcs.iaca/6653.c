#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * s1, uint8_t * d, int w, const uint8_t * s2)
{
  for (; w > 0; w--)
    {
      d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
      s1 += 2;
      s2 += 2;
      d++;
    }
}
