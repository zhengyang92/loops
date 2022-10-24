#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*opt)[35768])
{
  IACA_START for (i = 0; i < ((1 << 15) + 3000); i++)
    {
      opt[0][i] = (__builtin_inff ());
     } IACA_END
}
