#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long long __m128i;

int
fn (int i, const uint8_t * b, int num_pairs, const uint8_t * a, __m128i sum)
{
  for (i = 0; i < num_pairs; ++i)
    {
      const __m128i a0 = _mm_loadu_si128 ((const __m128i *) &a[32 * 0]);
      const __m128i b0 = _mm_loadu_si128 ((const __m128i *) &b[32 * 0]);
      const __m128i a1 = _mm_loadu_si128 ((const __m128i *) &a[32 * 1]);
      const __m128i b1 = _mm_loadu_si128 ((const __m128i *) &b[32 * 1]);
      __m128i sum1, sum2;
      SubtractAndAccumulate_SSE2 (a0, b0, &sum1);
      SubtractAndAccumulate_SSE2 (a1, b1, &sum2);
      sum = _mm_add_epi32 (sum, _mm_add_epi32 (sum1, sum2));
      a += 2 * 32;
      b += 2 * 32;
}}
