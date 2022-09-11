#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long long __m128i;

int
fn (int j, int i, uint8_t * y, __m128i bgr_plane[6])
{
  for (j = 0; j < 2; ++j, i += 16)
    {
      const __m128i zero = _mm_setzero_si128 ();
      __m128i r, g, b, Y0, Y1;
      b = _mm_unpacklo_epi8 (bgr_plane[0 + j], zero);
      g = _mm_unpacklo_epi8 (bgr_plane[2 + j], zero);
      r = _mm_unpacklo_epi8 (bgr_plane[4 + j], zero);
      ConvertRGBToY_SSE2 (&r, &g, &b, &Y0);
      b = _mm_unpackhi_epi8 (bgr_plane[0 + j], zero);
      g = _mm_unpackhi_epi8 (bgr_plane[2 + j], zero);
      r = _mm_unpackhi_epi8 (bgr_plane[4 + j], zero);
      ConvertRGBToY_SSE2 (&r, &g, &b, &Y1);
      _mm_storeu_si128 ((__m128i *) (y + i), (_mm_packus_epi16 (Y0, Y1)));
}}
