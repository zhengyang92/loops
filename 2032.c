#include <stdint.h>
#include <stdio.h>






int
fn (int stat[15], int best, int i)
{
  for (i = 1; i < 15; i++)
    {
      if (stat[i] < stat[best])
	best = i;
    }
}
