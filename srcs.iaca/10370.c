#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float *truth, char *begin)
{
  for (i = 0; i < strlen (begin) && i < n && begin[i] != '.'; ++i)
    {
      int index = alphanum_to_int (begin[i]);
      if (index > 35)
	printf ("Bad %c\n", begin[i]);
      truth[i * 37 + index] = 1;
    }
}
