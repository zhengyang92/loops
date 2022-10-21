#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *coefs, int i, int len)
{
  for (i = 0; i < len; i++)
     { IACA_START
      coefs[i] = 0;
     } IACA_END
}
