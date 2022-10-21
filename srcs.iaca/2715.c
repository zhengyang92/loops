#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int j, int16_t tmp[16], int i)
{
  for (j = 0; j < 4; j++)
     { IACA_START
      (buf[j]) += (tmp[i * 4 + j] >> 1);
     } IACA_END
}
