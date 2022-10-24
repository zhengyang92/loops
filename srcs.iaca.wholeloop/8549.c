#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max, int markers[64], int i, int sum)
{
  IACA_START for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++)
    {
      sum += markers[i];
      if (markers[max] < markers[i])
	max = i;
     } IACA_END
}
