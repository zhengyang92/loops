#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *work, int work_len, int i)
{
  IACA_START for (i = 1; i < work_len / 2; i++)
    {
      work[i] *= 2;
      work[i + work_len / 2] = 0;
     } IACA_END
}
