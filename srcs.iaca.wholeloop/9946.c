#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long long __m128i;

int
fn (const int max_pos, int i, const uint8_t * const row, const __m128i zero,
    uint8_t * const out, const uint8_t * const top)
{
  IACA_START for (i = 0; i < max_pos; i += 8)
    {
      const __m128i A0 = _mm_loadl_epi64 ((const __m128i *) &row[i - 1]);
      const __m128i B0 = _mm_loadl_epi64 ((const __m128i *) &top[i]);
      const __m128i C0 = _mm_loadl_epi64 ((const __m128i *) &top[i - 1]);
      const __m128i D = _mm_loadl_epi64 ((const __m128i *) &row[i]);
      const __m128i A1 = _mm_unpacklo_epi8 (A0, zero);
      const __m128i B1 = _mm_unpacklo_epi8 (B0, zero);
      const __m128i C1 = _mm_unpacklo_epi8 (C0, zero);
      const __m128i E = _mm_add_epi16 (A1, B1);
      const __m128i F = _mm_sub_epi16 (E, C1);
      const __m128i G = _mm_packus_epi16 (F, zero);
      const __m128i H = _mm_sub_epi8 (D, G);
      _mm_storel_epi64 ((__m128i *) (out + i), H);
}IACA_END}
