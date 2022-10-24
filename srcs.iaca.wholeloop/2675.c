#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int sub_len, int *p, unsigned int sub_count, unsigned int i,
    int *block_p)
{
  IACA_START for (i = 0, p = block_p; i < sub_count; i++)
    {
      p[0]++;
      p += sub_len;
     } IACA_END
}
