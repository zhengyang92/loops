#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (uint16_t * in_lines_cur[2], int i, int linesize, const int16_t * coef,
    int32_t * work_line)
{
  for (i = 0; i < linesize; i++)
    {
      *work_line = *in_lines_cur[0]++ * coef[0];
      *work_line++ += *in_lines_cur[1]++ * coef[1];
    }
}
