#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef __uint32_t uint32_t;

int
fn (int i, int level[16], int16_t * block, int total_coeff,
    const uint8_t * scantable, const uint32_t * qmul)
{
  IACA_START for (; i < total_coeff; i++)
    {
      scantable--;
      ((int32_t *) block)[*scantable] =
	((int) (level[i] * qmul[*scantable] + 32)) >> 6;
}IACA_END}
