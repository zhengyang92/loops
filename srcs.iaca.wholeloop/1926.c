#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int lwc_val[17], int *msk_val, int i)
{
  IACA_START for (i = 0; i < 16; i++)
    {
      int v = ((lwc_val[i]) > (-512) ? (lwc_val[i]) : (-512));
      msk_val[i] = ((msk_val[i] + v) > (0) ? (msk_val[i] + v) : (0));
}IACA_END}
