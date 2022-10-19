#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long long __m128i;

int
fn (const __m128i top_base_1, int y, const __m128i top_base_0,
    const uint8_t * top, uint8_t * dst)
{
  for (y = 0; y < 16; ++y, dst += 32)
    {
      const int val = dst[-1] - top[-1];
      const __m128i base = _mm_set1_epi16 (val);
      const __m128i out_0 = _mm_add_epi16 (base, top_base_0);
      const __m128i out_1 = _mm_add_epi16 (base, top_base_1);
      const __m128i out = _mm_packus_epi16 (out_0, out_1);
      _mm_storeu_si128 ((__m128i *) dst, out);
}}
