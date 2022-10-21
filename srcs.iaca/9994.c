#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (int j, __m128i rgb_plane[6], int i, uint8_t * y)
{
  for (j = 0; j < 2; ++j, i += 16)
     { IACA_START
      const __m128i zero = _mm_setzero_si128 ();
      __m128i r, g, b, Y0, Y1;
      r = _mm_unpacklo_epi8 (rgb_plane[0 + j], zero);
      g = _mm_unpacklo_epi8 (rgb_plane[2 + j], zero);
      b = _mm_unpacklo_epi8 (rgb_plane[4 + j], zero);
      ConvertRGBToY_SSE2 (&r, &g, &b, &Y0);
      r = _mm_unpackhi_epi8 (rgb_plane[0 + j], zero);
      g = _mm_unpackhi_epi8 (rgb_plane[2 + j], zero);
      b = _mm_unpackhi_epi8 (rgb_plane[4 + j], zero);
      ConvertRGBToY_SSE2 (&r, &g, &b, &Y1);
      _mm_storeu_si128 ((__m128i *) (y + i), (_mm_packus_epi16 (Y0, Y1)));
} IACA_END }
