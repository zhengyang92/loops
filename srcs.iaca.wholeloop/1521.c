#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int *sinptr, int (*filter)[8][2], int bands, int n,
    const int *proto, int coshalf, int c, int s, const int *cosptr,
    int sinhalf, int q)
{
  IACA_START for (n = 0; n < 7; n++)
    {
      int theta = (q * (n - 6) + (n >> 1) - 3) % bands;
      if (theta < 0)
	theta += bands;
      s = sinptr[theta];
      c = cosptr[theta];
      if (n & 1)
	{
	  theta =
	    (int) (((int64_t) c * coshalf - (int64_t) s * sinhalf +
		    0x20000000) >> 30);
	  s =
	    (int) (((int64_t) s * coshalf + (int64_t) c * sinhalf +
		    0x20000000) >> 30);
	  c = theta;
	}
      filter[q][n][0] = (int) (((int64_t) proto[n] * c + 0x20000000) >> 30);
      filter[q][n][1] = -(int) (((int64_t) proto[n] * s + 0x20000000) >> 30);
}IACA_END}
