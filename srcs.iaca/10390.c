#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, char **labels, char **paths, int truth)
{
  for (j = 0; j < 13; ++j)
     { IACA_START
      if (strstr (paths[i], labels[j]))
	truth = j;
     } IACA_END
}
