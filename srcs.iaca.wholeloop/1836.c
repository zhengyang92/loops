#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const float *src, int i, float prev, ptrdiff_t len, float *dst)
{
  IACA_START for (i = 0; i < len; i++)
    {
      float a = 0.25f * src[i] + 0.75f * prev;
      float b = 0.75f * src[i] + 0.25f * prev;
      prev = src[i];
      *dst++ = a;
      *dst++ = b;
}IACA_END}
