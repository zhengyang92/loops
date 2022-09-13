#include <stdint.h>
#include <stdio.h>






int
fn (int sumX, const int *X, const int *Y, int i)
{
  double retval = 0.;
  int sumXY = 0;
  for (i = 0; i < 256; ++i)
    {
      const int x = X[i];
      if (x != 0)
	{
	  const int xy = x + Y[i];
	  sumX += x;
	  retval -= VP8LFastSLog2 (x);
	  sumXY += xy;
	  retval -= VP8LFastSLog2 (xy);
	}
      else if (Y[i] != 0)
	{
	  sumXY += Y[i];
	  retval -= VP8LFastSLog2 (Y[i]);
	}
    }
}
