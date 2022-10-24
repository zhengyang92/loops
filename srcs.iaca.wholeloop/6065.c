#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int ccr_buf[80], int j, int16_t flt_buf[5][60])
{
  int count = 0;
  IACA_START for (j = 0; j < 5; j++)
    {
      ccr_buf[count++] = ff_g723_1_dot_product (flt_buf[j], flt_buf[j], 60);
     } IACA_END
}
