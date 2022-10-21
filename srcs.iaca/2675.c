#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int sub_len, int *p, unsigned int sub_count, unsigned int i,
    int *block_p)
{
  for (i = 0, p = block_p; i < sub_count; i++)
     { IACA_START
      p[0]++;
      p += sub_len;
     } IACA_END
}
