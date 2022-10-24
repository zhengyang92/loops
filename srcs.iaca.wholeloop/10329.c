#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int signed_stride, int i, unsigned char *z, signed char *line_buffer,
    int type, int n)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      switch (type)
	{
	case 0:
	  line_buffer[i] = z[i];
	  break;
	case 1:
	  line_buffer[i] = z[i];
	  break;
	case 2:
	  line_buffer[i] = z[i] - z[i - signed_stride];
	  break;
	case 3:
	  line_buffer[i] = z[i] - (z[i - signed_stride] >> 1);
	  break;
	case 4:
	  line_buffer[i] =
	    (signed char) (z[i] - stbiw__paeth (0, z[i - signed_stride], 0));
	  break;
	case 5:
	  line_buffer[i] = z[i];
	  break;
	case 6:
	  line_buffer[i] = z[i];
	  break;
	}
     } IACA_END
}
