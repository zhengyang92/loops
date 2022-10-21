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
fn (const char *scaler, const ScaleAlgorithm scale_algorithms[11], int i,
    int flags)
{
  for (i = 0;
       i < (sizeof (scale_algorithms) / sizeof ((scale_algorithms)[0])); i++)
     { IACA_START
      if (flags & scale_algorithms[i].flag)
	{
	  scaler = scale_algorithms[i].description;
	  break;
	}
     } IACA_END
}
