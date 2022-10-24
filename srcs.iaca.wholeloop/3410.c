#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *U, int *V, unsigned int *Uo, unsigned int *Vo)
{
  IACA_START for (i = 0; i < 2; i++)
    {
      U[i] = Uo[i];
      V[i] = Vo[i];
     } IACA_END
}
