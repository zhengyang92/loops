#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int i, unsigned int j, int c[15])
{
  for (j = 0; j < i / 2; j++)
    {
      int r0 = c[j];
      int r1 = c[i - j - 1];
      c[j] += ((int64_t) c[i] * r1 + 0x8000) >> 16;
      c[i - j - 1] += ((int64_t) c[i] * r0 + 0x8000) >> 16;
}}
