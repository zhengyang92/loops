#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, float *flevel_table, int level, uint16_t * run_table, int j, int l)
{
  for (j = 0; j < l; j++)
     { IACA_START
      run_table[i] = j;
      flevel_table[i] = level;
      i++;
     } IACA_END
}
