#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * alpha, __m128i all_alphas, const int limit,
    const __m128i * src, const __m128i a_mask)
{
  for (i = 0; i < limit; i += 8)
    {
      const __m128i a0 = _mm_loadu_si128 (src + 0);
      const __m128i a1 = _mm_loadu_si128 (src + 1);
      const __m128i b0 = _mm_and_si128 (a0, a_mask);
      const __m128i b1 = _mm_and_si128 (a1, a_mask);
      const __m128i c0 = _mm_packs_epi32 (b0, b1);
      const __m128i d0 = _mm_packus_epi16 (c0, c0);
      _mm_storel_epi64 ((__m128i *) & alpha[i], d0);
      all_alphas = _mm_and_si128 (all_alphas, d0);
      src += 2;
}}
