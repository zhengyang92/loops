#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int table_size, int i, int16_t (*table)[2])
{
  for (i = 0; i < table_size; i++)
     { IACA_START
      table[i][1] = 0;
      table[i][0] = -1;
     } IACA_END
}
