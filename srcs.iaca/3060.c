#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (ptrdiff_t stride, int16_t * ptr, int k, int16_t * tmp,
    unsigned int scaled_height)
{
  for (k = 0; k < scaled_height; k++)
    {
      tmp[k] = *ptr;
      ptr += stride;
    }
}
