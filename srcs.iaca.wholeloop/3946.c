#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct
{
  int flag;
  const char *description;
  int size_factor;
} ScaleAlgorithm;

int
fn (int sizeFactor, const ScaleAlgorithm scale_algorithms[11], int i,
    int flags)
{
  IACA_START for (i = 0;
       i < (sizeof (scale_algorithms) / sizeof ((scale_algorithms)[0])); i++)
    {
      if (flags & scale_algorithms[i].flag
	  && scale_algorithms[i].size_factor > 0)
	{
	  sizeFactor = scale_algorithms[i].size_factor;
	  break;
	}
     } IACA_END
}
