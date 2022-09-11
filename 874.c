#include <stdint.h>
#include <stdio.h>






int
fn (float *data, int mid, float x, int low, int hi)
{
  for (;;)
    {
      do
	{
	  if (!(x >= data[low]))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "x >= data[low]", "program.c", 847);
	      abort ();
	    }
	}
      while (0);
      do
	{
	  if (!(x <= data[hi]))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "x <= data[hi]", "program.c", 848);
	      abort ();
	    }
	}
      while (0);
      do
	{
	  if (!((hi - low) > 0))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "(hi-low) > 0", "program.c", 849);
	      abort ();
	    }
	}
      while (0);
      if (hi - low == 1)
	return low;
      mid = (low + hi) / 2;
      if (x < data[mid])
	hi = mid;
      else
	low = mid;
    }
}
