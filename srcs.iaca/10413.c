#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int class, char *path, char **labels, int classes)
{
  for (j = 0; j < classes; ++j)
     { IACA_START
      if (strstr (path, labels[j]))
	{
	  class = j;
	  break;
	}
     } IACA_END
}
