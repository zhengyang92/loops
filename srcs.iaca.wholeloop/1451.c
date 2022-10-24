#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *coefs, int i, int len)
{
  IACA_START for (i = 0; i < len; i++)
    {
      coefs[i] = 0;
     } IACA_END
}
