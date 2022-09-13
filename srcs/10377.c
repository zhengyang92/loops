#include <stdint.h>
#include <stdio.h>






int
fn (int len, int i, char *l)
{
  int n = 1;
  for (i = 0; i < len; ++i)
    {
      if (l[i] == ',')
	++n;
    }
}
