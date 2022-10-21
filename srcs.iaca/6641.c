#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int last, int i, int16_t temp[64], int16_t * block,
    const uint8_t * scantable)
{
  for (i = 0; i <= last; i++)
     { IACA_START
      const int j = scantable[i];
      temp[j] = block[j];
      block[j] = 0;
} IACA_END }
