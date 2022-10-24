#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef long long __m128i;

int
fn (const __m128i black, int i, const uint32_t * in, uint32_t * out,
    int num_pixels)
{
  IACA_START for (i = 0; i + 4 <= num_pixels; i += 4)
    {
      const __m128i src = _mm_loadu_si128 ((const __m128i *) &in[i]);
      const __m128i res = _mm_sub_epi8 (src, black);
      _mm_storeu_si128 ((__m128i *) & out[i], res);
}IACA_END}
