#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint8_t * const row, int x, int width, const __m128i mask_or,
    const __m128i mask_mul, uint32_t * dst, const __m128i mul_cst)
{
  for (x = 0; x + 16 <= width; x += 16, dst += 4)
    {
      const __m128i in = _mm_loadu_si128 ((const __m128i *) &row[x]);
      const __m128i mul = _mm_mullo_epi16 (in, mul_cst);
      const __m128i tmp = _mm_and_si128 (mul, mask_mul);
      const __m128i shift = _mm_srli_epi32 (tmp, 12);
      const __m128i pack = _mm_or_si128 (shift, tmp);
      const __m128i res = _mm_or_si128 (pack, mask_or);
      _mm_storeu_si128 ((__m128i *) dst, res);
}}
