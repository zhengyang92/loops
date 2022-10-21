#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int (*buckets)[256], int v)
{
  for (j = 0; j < 4; j++)
     { IACA_START
      buckets[j][get_bucket (v, 0)]++;
      v >>= 8;
     } IACA_END
}
