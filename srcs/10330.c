#include <stdint.h>
#include <stdio.h>






int
fn (int signed_stride, int i, int width, unsigned char *z,
    signed char *line_buffer, int type, int n)
{
  for (i = n; i < width * n; ++i)
    {
      switch (type)
	{
	case 0:
	  line_buffer[i] = z[i];
	  break;
	case 1:
	  line_buffer[i] = z[i] - z[i - n];
	  break;
	case 2:
	  line_buffer[i] = z[i] - z[i - signed_stride];
	  break;
	case 3:
	  line_buffer[i] = z[i] - ((z[i - n] + z[i - signed_stride]) >> 1);
	  break;
	case 4:
	  line_buffer[i] =
	    z[i] - stbiw__paeth (z[i - n], z[i - signed_stride],
				 z[i - signed_stride - n]);
	  break;
	case 5:
	  line_buffer[i] = z[i] - (z[i - n] >> 1);
	  break;
	case 6:
	  line_buffer[i] = z[i] - stbiw__paeth (z[i - n], 0, 0);
	  break;
	}
    }
}
