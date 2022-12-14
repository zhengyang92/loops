#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (uint8_t ** in_lines_cur, int i, uint8_t ** in_lines_adj, int linesize,
    const int16_t * coef, int32_t * work_line)
{
  IACA_START for (i = 0; i < linesize; i++)
    {
      *work_line += *in_lines_cur[0]++ * coef[0];
      *work_line += *in_lines_adj[0]++ * coef[0];
      *work_line += *in_lines_cur[1]++ * coef[1];
      *work_line += *in_lines_adj[1]++ * coef[1];
      *work_line += *in_lines_cur[2]++ * coef[2];
      *work_line++ += *in_lines_adj[2]++ * coef[2];
     } IACA_END
}
