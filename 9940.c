#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (const __m128i top_base_1, int y, const __m128i top_base_0,
    const uint8_t * left, uint8_t * dst)
{
  for (y = 0; y < 16; ++y, dst += 32)
    {
      const int val = left[y] - left[-1];
      const __m128i base = _mm_set1_epi16 (val);
      const __m128i out_0 = _mm_add_epi16 (base, top_base_0);
      const __m128i out_1 = _mm_add_epi16 (base, top_base_1);
      const __m128i out = _mm_packus_epi16 (out_0, out_1);
      _mm_store_si128 ((__m128i *) dst, out);
}}
