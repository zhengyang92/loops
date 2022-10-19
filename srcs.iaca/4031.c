#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const color_range_names[3], int i)
{
  for (i = 0;
       i < (sizeof (color_range_names) / sizeof ((color_range_names)[0]));
       i++)
    {
      if (av_strstart (name, color_range_names[i], ((void *) 0)))
	return i;
    }
}
