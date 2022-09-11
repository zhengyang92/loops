#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;
typedef int DWTELEM;

int
fn (int y, const int qmul, int thres2, DWTELEM * src, int x, const int w,
    int thres1, IDWTELEM * dst, int stride)
{
  for (x = 0; x < w; x++)
    {
      int i = src[x + y * stride];
      if ((unsigned) (i + thres1) > thres2)
	{
	  if (i >= 0)
	    {
	      i <<= (7 - 4 + 8);
	      i /= qmul;
	      dst[x + y * stride] = i;
	    }
	  else
	    {
	      i = -i;
	      i <<= (7 - 4 + 8);
	      i /= qmul;
	      dst[x + y * stride] = -i;
	    }
	}
      else
	dst[x + y * stride] = 0;
    }
}
