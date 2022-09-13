#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *scratch, int ncomp, int width, float *scanline, int x,
    float linear[3], unsigned char rgbe[4])
{
  for (x = 0; x < width; x++)
    {
      switch (ncomp)
	{
	case 4:
	case 3:
	  linear[2] = scanline[x * ncomp + 2];
	  linear[1] = scanline[x * ncomp + 1];
	  linear[0] = scanline[x * ncomp + 0];
	  break;
	default:
	  linear[0] = linear[1] = linear[2] = scanline[x * ncomp + 0];
	  break;
	}
      stbiw__linear_to_rgbe (rgbe, linear);
      scratch[x + width * 0] = rgbe[0];
      scratch[x + width * 1] = rgbe[1];
      scratch[x + width * 2] = rgbe[2];
      scratch[x + width * 3] = rgbe[3];
    }
}
