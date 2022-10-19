#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, const __m128i zero, const int limit, uint32_t * dst,
    const uint8_t * alpha)
{
  for (i = 0; i < limit; i += 16)
    {
      const __m128i a0 = _mm_loadu_si128 ((const __m128i *) &alpha[i]);
      const __m128i a1 = _mm_unpacklo_epi8 (zero, a0);
      const __m128i b1 = _mm_unpackhi_epi8 (zero, a0);
      const __m128i a2_lo = _mm_unpacklo_epi16 (a1, zero);
      const __m128i b2_lo = _mm_unpacklo_epi16 (b1, zero);
      const __m128i a2_hi = _mm_unpackhi_epi16 (a1, zero);
      const __m128i b2_hi = _mm_unpackhi_epi16 (b1, zero);
      _mm_storeu_si128 ((__m128i *) & dst[i + 0], a2_lo);
      _mm_storeu_si128 ((__m128i *) & dst[i + 4], a2_hi);
      _mm_storeu_si128 ((__m128i *) & dst[i + 8], b2_lo);
      _mm_storeu_si128 ((__m128i *) & dst[i + 12], b2_hi);
}}
