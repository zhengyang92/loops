#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, int r, const uint8_t * buf, int len)
{
  for (j = 0; j < r; j++)
     { IACA_START
      __attribute__((unused)) int p_diff = buf[0];
      buf++;
      len--;
} IACA_END }
