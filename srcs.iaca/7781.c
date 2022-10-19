#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t * src, ptrdiff_t size, int p)
{
  for (ptrdiff_t i = 1; i < size; i++)
    {
      int d = src[i] - p + 384;
      p = src[i];
      src[i] = d;
}}
