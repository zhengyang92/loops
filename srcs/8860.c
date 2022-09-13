#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (const int qmul, int x, const int qadd, const int w, IDWTELEM * line)
{
  for (x = 0; x < w; x++)
    {
      int i = line[x];
      if (i < 0)
	{
	  line[x] = -((-i * (unsigned) qmul + qadd) >> ((7 - 4 + 8)));
	}
      else if (i > 0)
	{
	  line[x] = ((i * (unsigned) qmul + qadd) >> ((7 - 4 + 8)));
	}
}}
