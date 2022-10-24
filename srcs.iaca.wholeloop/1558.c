#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int attacks[9], int i)
{
  int grouping = 0;
  IACA_START for (i = 0; i < 9; i++)
    {
      if (attacks[i])
	{
	  grouping = i;
	  break;
	}
     } IACA_END
}
