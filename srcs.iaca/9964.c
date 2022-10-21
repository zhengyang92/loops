#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint8_t * const row, const __m128i zero, const __m128i ff, int x,
    int width, uint32_t * dst)
{
  for (x = 0; x + 16 <= width; x += 16, dst += 16)
     { IACA_START
      const __m128i in = _mm_loadu_si128 ((const __m128i *) &row[x]);
      const __m128i in_lo = _mm_unpacklo_epi8 (zero, in);
      const __m128i dst0 = _mm_unpacklo_epi16 (in_lo, ff);
      const __m128i dst1 = _mm_unpackhi_epi16 (in_lo, ff);
      const __m128i in_hi = _mm_unpackhi_epi8 (zero, in);
      const __m128i dst2 = _mm_unpacklo_epi16 (in_hi, ff);
      const __m128i dst3 = _mm_unpackhi_epi16 (in_hi, ff);
      _mm_storeu_si128 ((__m128i *) & dst[0], dst0);
      _mm_storeu_si128 ((__m128i *) & dst[4], dst1);
      _mm_storeu_si128 ((__m128i *) & dst[8], dst2);
      _mm_storeu_si128 ((__m128i *) & dst[12], dst3);
} IACA_END }
