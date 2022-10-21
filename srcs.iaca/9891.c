#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (int i, const __m128i zero, const int limit, __m128i all_alphas,
    __m128i * out, const uint8_t * alpha, const __m128i rgb_mask)
{
  for (i = 0; i < limit; i += 8)
     { IACA_START
      const __m128i a0 = _mm_loadl_epi64 ((const __m128i *) &alpha[i]);
      const __m128i a1 = _mm_unpacklo_epi8 (a0, zero);
      const __m128i a2_lo = _mm_unpacklo_epi16 (a1, zero);
      const __m128i a2_hi = _mm_unpackhi_epi16 (a1, zero);
      const __m128i b0_lo = _mm_loadu_si128 (out + 0);
      const __m128i b0_hi = _mm_loadu_si128 (out + 1);
      const __m128i b1_lo = _mm_and_si128 (b0_lo, rgb_mask);
      const __m128i b1_hi = _mm_and_si128 (b0_hi, rgb_mask);
      const __m128i b2_lo = _mm_or_si128 (b1_lo, a2_lo);
      const __m128i b2_hi = _mm_or_si128 (b1_hi, a2_hi);
      _mm_storeu_si128 (out + 0, b2_lo);
      _mm_storeu_si128 (out + 1, b2_hi);
      all_alphas = _mm_and_si128 (all_alphas, a0);
      out += 2;
} IACA_END }
