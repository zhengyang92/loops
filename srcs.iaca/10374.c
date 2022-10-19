#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *next, int i, float *a, int n, char *curr)
{
  int done = 0;
  for (i = 0; i < n && !done; ++i)
    {
      while (*++next != '\0' && *next != ',');
      if (*next == '\0')
	done = 1;
      *next = '\0';
      sscanf (curr, "%g", &a[i]);
      curr = next + 1;
    }
}
