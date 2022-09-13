#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (int i, BitstreamContext * bc, int wlength, int mode, int coding_mode[128])
{
  for (i = 1; i < wlength; i++)
    {
      int c = get_unary (bc, 1, 6);
      switch (c)
	{
	case 6:
	  mode = bitstream_read (bc, 6);
	  break;
	case 5:
	case 4:
	case 3:
	  {
	    int sign = bitstream_read_bit (bc);
	    mode += (-sign ^ (c - 1)) + sign;
	    break;
	  }
	case 2:
	  mode++;
	  break;
	case 1:
	  mode--;
	  break;
	}
      coding_mode[i] = mode;
    }
}
