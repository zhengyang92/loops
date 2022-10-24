#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef stbi__write_context;

int
fn (unsigned char *scratch, int width, int c, stbi__write_context * s, int x,
    int r)
{
  IACA_START for (c = 0; c < 4; c++)
    {
      unsigned char *comp = &scratch[width * c];
      x = 0;
      while (x < width)
	{
	  r = x;
	  while (r + 2 < width)
	    {
	      if (comp[r] == comp[r + 1] && comp[r] == comp[r + 2])
		break;
	      ++r;
	    }
	  if (r + 2 >= width)
	    r = width;
	  while (x < r)
	    {
	      int len = r - x;
	      if (len > 128)
		len = 128;
	      stbiw__write_dump_data (s, len, &comp[x]);
	      x += len;
	    }
	  if (r + 2 < width)
	    {
	      while (r < width && comp[r] == comp[x])
		++r;
	      while (x < r)
		{
		  int len = r - x;
		  if (len > 127)
		    len = 127;
		  stbiw__write_run_data (s, len, comp[x]);
		  x += len;
		}
	    }
	}
     } IACA_END
}
