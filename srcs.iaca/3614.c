#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t v[30], const uint8_t * left, int i)
{
  for (i = 0; i < 16 - 2; i++)
    {
      v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
      v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
    }
}
