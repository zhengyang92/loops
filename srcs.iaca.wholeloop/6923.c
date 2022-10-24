#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *Vo, int i, int *U, int *Uo, int *V)
{
  IACA_START for (i = 0; i < 2; i++)
    {
      U[i] = Uo[i];
      V[i] = Vo[i];
     } IACA_END
}
