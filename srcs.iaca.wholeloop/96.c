#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float ac[5])
{
  IACA_START for (int i = 1; i <= 4; i++)
    {
      ac[i] -= ac[i] * (.008f * i) * (.008f * i);
}IACA_END}
