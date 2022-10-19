#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * const alpha, const __m128i zero, uint8_t * const ptr,
    int width, const __m128i kMult, const __m128i k128)
{
  int x = 0;
  for (x = 0; x + 8 <= width; x += 8)
    {
      const __m128i v0 = _mm_loadl_epi64 ((__m128i *) & ptr[x]);
      const __m128i a0 = _mm_loadl_epi64 ((const __m128i *) &alpha[x]);
      const __m128i v1 = _mm_unpacklo_epi8 (v0, zero);
      const __m128i a1 = _mm_unpacklo_epi8 (a0, zero);
      const __m128i v2 = _mm_mullo_epi16 (v1, a1);
      const __m128i v3 = _mm_add_epi16 (v2, k128);
      const __m128i v4 = _mm_mulhi_epu16 (v3, kMult);
      const __m128i v5 = _mm_packus_epi16 (v4, zero);
      _mm_storel_epi64 ((__m128i *) & ptr[x], v5);
}}
