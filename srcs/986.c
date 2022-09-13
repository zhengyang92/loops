#include <stdint.h>
#include <stdio.h>






int
fn (int ***mask, int c, int a, int b)
{
  for (c = -a; c <= a; c++)
    {
      if ((b * b) + (c * c) <= (a * a))
	mask[a][b + a][c + a] = 1;
      else
	mask[a][b + a][c + a] = 0;
    }
}
