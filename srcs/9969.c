#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef long long __m128i;

int
fn (int i, const __m128i zero, const uint32_t * in, uint32_t * out,
    int num_pixels, const uint32_t * upper)
{
  for (i = 0; i + 2 <= num_pixels; i += 2)
    {
      const __m128i L = _mm_loadl_epi64 ((const __m128i *) &in[i - 1]);
      const __m128i src = _mm_loadl_epi64 ((const __m128i *) &in[i]);
      const __m128i T = _mm_loadl_epi64 ((const __m128i *) &upper[i]);
      const __m128i TL = _mm_loadl_epi64 ((const __m128i *) &upper[i - 1]);
      const __m128i L_lo = _mm_unpacklo_epi8 (L, zero);
      const __m128i T_lo = _mm_unpacklo_epi8 (T, zero);
      const __m128i TL_lo = _mm_unpacklo_epi8 (TL, zero);
      const __m128i sum = _mm_add_epi16 (T_lo, L_lo);
      const __m128i avg = _mm_srli_epi16 (sum, 1);
      const __m128i A1 = _mm_sub_epi16 (avg, TL_lo);
      const __m128i bit_fix = _mm_cmpgt_epi16 (TL_lo, avg);
      const __m128i A2 = _mm_sub_epi16 (A1, bit_fix);
      const __m128i A3 = _mm_srai_epi16 (A2, 1);
      const __m128i A4 = _mm_add_epi16 (avg, A3);
      const __m128i pred = _mm_packus_epi16 (A4, A4);
      const __m128i res = _mm_sub_epi8 (src, pred);
      _mm_storel_epi64 ((__m128i *) & out[i], res);
}}
