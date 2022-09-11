#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const __m128i mul, const uint8_t * const row, const __m128i ff, int x,
    int width, uint32_t * dst)
{
  for (x = 0; x + 16 <= width; x += 16, dst += 8)
    {
      const __m128i in = _mm_loadu_si128 ((const __m128i *) &row[x]);
      const __m128i tmp = _mm_mullo_epi16 (in, mul);
      const __m128i pack = _mm_and_si128 (tmp, ff);
      const __m128i dst0 = _mm_unpacklo_epi16 (pack, ff);
      const __m128i dst1 = _mm_unpackhi_epi16 (pack, ff);
      _mm_storeu_si128 ((__m128i *) & dst[0], dst0);
      _mm_storeu_si128 ((__m128i *) & dst[4], dst1);
}}
