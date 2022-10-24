#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max, int i, int sum, int markers[3])
{
  IACA_START for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++)
    {
      sum += markers[i];
      if (markers[max] < markers[i])
	max = i;
     } IACA_END
}
