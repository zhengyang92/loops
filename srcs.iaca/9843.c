#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float __m128;
typedef int32_t OPJ_INT32;

int
fn (OPJ_INT32 m, __m128 c, OPJ_INT32 k, __m128 * __restrict vw)
{
  for (; m < k; ++m)
    {
      __m128 tmp = vw[-1];
      vw[-1] = _mm_add_ps (tmp, c);
      vw += 2;
    }
}
