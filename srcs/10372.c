#include <stdint.h>
#include <stdio.h>






int
fn (char *path, int i, char **labels, int k, float *truth)
{
  int count = 0;
  for (i = 0; i < k; ++i)
    {
      if (strstr (path, labels[i]))
	{
	  truth[i] = 1;
	  ++count;
	}
    }
}
