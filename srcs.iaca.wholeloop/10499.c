#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t width_max, const char *msgs[3])
{
  IACA_START for (unsigned i = 0; i < (sizeof (msgs) / sizeof ((msgs)[0])); ++i)
    {
      size_t w = tuklib_mbstr_width (msgs[i], ((void *) 0));
      ((void) (0));
      if (w == (size_t) -1)
	w = 1;
      if (width_max < w)
	width_max = w;
     } IACA_END
}
