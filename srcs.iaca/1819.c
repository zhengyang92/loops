#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int j, int32_t * ptr, int len, const int pred_id)
{
  for (j = 0; j < len; j++)
     { IACA_START
      int32_t x = ff_dcaadpcm_predict (pred_id, ptr + j - 4);
      ptr[j] = clip23 (ptr[j] + x);
     } IACA_END
}
