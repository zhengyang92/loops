#include <stdint.h>
#include <stdio.h>






int
fn (const int idx2, int image_histo_size, int i, int *const clusters)
{
  for (i = 0; i + 1 < image_histo_size; ++i)
    {
      if (clusters[i] >= idx2)
	{
	  clusters[i] = clusters[i + 1];
	}
    }
}
