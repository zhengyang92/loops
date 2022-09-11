#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (int y, const __m128i zero, const __m128i top_base, const uint8_t * top,
    uint8_t * dst)
{
  for (y = 0; y < 4; ++y, dst += 32)
    {
      const int val = dst[-1] - top[-1];
      const __m128i base = _mm_set1_epi16 (val);
      const __m128i out =
	_mm_packus_epi16 (_mm_add_epi16 (base, top_base), zero);
      WebPUint32ToMem (dst, _mm_cvtsi128_si32 (out));
}}
