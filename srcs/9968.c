#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint32_t uint32_t;

int
fn (int i, const __m128i zero, const uint32_t * in, uint32_t * out,
    int num_pixels, const uint32_t * upper)
{
  for (i = 0; i + 4 <= num_pixels; i += 4)
    {
      const __m128i src = _mm_loadu_si128 ((const __m128i *) &in[i]);
      const __m128i L = _mm_loadu_si128 ((const __m128i *) &in[i - 1]);
      const __m128i L_lo = _mm_unpacklo_epi8 (L, zero);
      const __m128i L_hi = _mm_unpackhi_epi8 (L, zero);
      const __m128i T = _mm_loadu_si128 ((const __m128i *) &upper[i]);
      const __m128i T_lo = _mm_unpacklo_epi8 (T, zero);
      const __m128i T_hi = _mm_unpackhi_epi8 (T, zero);
      const __m128i TL = _mm_loadu_si128 ((const __m128i *) &upper[i - 1]);
      const __m128i TL_lo = _mm_unpacklo_epi8 (TL, zero);
      const __m128i TL_hi = _mm_unpackhi_epi8 (TL, zero);
      const __m128i diff_lo = _mm_sub_epi16 (T_lo, TL_lo);
      const __m128i diff_hi = _mm_sub_epi16 (T_hi, TL_hi);
      const __m128i pred_lo = _mm_add_epi16 (L_lo, diff_lo);
      const __m128i pred_hi = _mm_add_epi16 (L_hi, diff_hi);
      const __m128i pred = _mm_packus_epi16 (pred_lo, pred_hi);
      const __m128i res = _mm_sub_epi8 (src, pred);
      _mm_storeu_si128 ((__m128i *) & out[i], res);
}}
