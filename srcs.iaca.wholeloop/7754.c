#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int (*counttab2)[256])
{
  IACA_START for (i = 0; i < 256; i++)
    {
      counttab2[i + 1][i] = 0;
     } IACA_END
}
