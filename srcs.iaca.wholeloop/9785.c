#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *Ncolors, int iroot, int i, int total_colors, int nc)
{
  IACA_START for (i = 0; i < nc; i++)
    {
      Ncolors[i] = iroot;
      total_colors *= iroot;
     } IACA_END
}
