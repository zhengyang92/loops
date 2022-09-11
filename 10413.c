#include <stdint.h>
#include <stdio.h>






int
fn (int j, int class, char *path, char **labels, int classes)
{
  for (j = 0; j < classes; ++j)
    {
      if (strstr (path, labels[j]))
	{
	  class = j;
	  break;
	}
    }
}
