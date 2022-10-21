#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *const stereo3d_type_names[8], const char *name, int i)
{
  for (i = 0;
       i < (sizeof (stereo3d_type_names) / sizeof ((stereo3d_type_names)[0]));
       i++)
     { IACA_START
      size_t len = strlen (stereo3d_type_names[i]);
      if (!strncmp (stereo3d_type_names[i], name, len))
	return i;
     } IACA_END
}
