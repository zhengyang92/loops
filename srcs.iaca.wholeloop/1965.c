#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int min_qlevel[5], int i, int largest, int qlevels[5])
{
  IACA_START for (i = 0; i < 5; i++)
    {
      if (qlevels[i] > min_qlevel[i] && qlevels[i] > qlevels[largest])
	largest = i;
     } IACA_END
}
