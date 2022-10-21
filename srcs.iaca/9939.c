#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (int y, const __m128i zero, const uint8_t * left, const __m128i top_base,
    uint8_t * dst)
{
  for (y = 0; y < 8; ++y, dst += 32)
     { IACA_START
      const int val = left[y] - left[-1];
      const __m128i base = _mm_set1_epi16 (val);
      const __m128i out =
	_mm_packus_epi16 (_mm_add_epi16 (base, top_base), zero);
      _mm_storel_epi64 ((__m128i *) dst, out);
} IACA_END }
