#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (const char *colon_strs[10], size_t lens[10], size_t widths[10],
    size_t width_max)
{
  IACA_START for (unsigned i = 0; i < (sizeof (colon_strs) / sizeof ((colon_strs)[0]));
       ++i)
    {
      widths[i] = tuklib_mbstr_width ((colon_strs[i]), &lens[i]);
      ((void) (0));
      if (widths[i] == (size_t) -1)
	widths[i] = lens[i];
      if (widths[i] > width_max)
	width_max = widths[i];
     } IACA_END
}
