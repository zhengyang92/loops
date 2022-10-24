#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const int16_t * const kker, const int iws, ptrdiff_t in_linesize,
    const int16_t * const vv, const int16_t * const uu,
    const uint16_t * const s)
{
  int tmp = 0;
  IACA_START for (int j = 0; j < 2; j++)
    {
      tmp += kker[iws + j] * s[vv[iws + j] * in_linesize + uu[iws + j]];
}IACA_END}
