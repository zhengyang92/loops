#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const int16_t * const kker, const uint8_t * const s, const int iws,
    ptrdiff_t in_linesize, const int16_t * const vv, const int16_t * const uu)
{
  int tmp = 0;
  IACA_START for (int j = 0; j < 2; j++)
    {
      tmp += kker[iws + j] * s[vv[iws + j] * in_linesize + uu[iws + j]];
}IACA_END}
