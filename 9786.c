#include <stdint.h>
#include <stdio.h>




typedef unsigned char JSAMPLE;
typedef long INT32;

int
fn (int numcolors, INT32 minmaxdist, int ncolors, int i, JSAMPLE * colorlist,
    INT32 mindist[256])
{
  for (i = 0; i < numcolors; i++)
    {
      if (mindist[i] <= minmaxdist)
	colorlist[ncolors++] = (JSAMPLE) i;
    }
}
