#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int last, uint8_t * permutation, int i, int16_t temp[64], int16_t * block,
    const uint8_t * scantable)
{
  for (i = 0; i <= last; i++)
     { IACA_START
      const int j = scantable[i];
      const int perm_j = permutation[j];
      block[perm_j] = temp[j];
} IACA_END }
