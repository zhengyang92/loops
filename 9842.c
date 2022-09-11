#include <stdint.h>
#include <stdio.h>




typedef float __m128;
typedef int32_t OPJ_INT32;

int
fn (__m128 * __restrict vw, __m128 tmp3, __m128 tmp2, __m128 tmp1,
    OPJ_INT32 i, OPJ_INT32 m, __m128 c)
{
  for (i = 0; i < m; ++i)
    {
      tmp2 = vw[-1];
      tmp3 = vw[0];
      vw[-1] = _mm_add_ps (tmp2, _mm_mul_ps (_mm_add_ps (tmp1, tmp3), c));
      tmp1 = tmp3;
      vw += 2;
    }
}
