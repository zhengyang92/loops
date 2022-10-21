#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (uint8_t ** in_lines_cur, int i, int linesize, const int16_t * coef,
    int32_t * work_line)
{
  for (i = 0; i < linesize; i++)
     { IACA_START
      *work_line = *in_lines_cur[0]++ * coef[0];
      *work_line++ += *in_lines_cur[1]++ * coef[1];
     } IACA_END
}
