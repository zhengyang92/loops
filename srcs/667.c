#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int nb_match_blocks, int k, float *bufferz,
    float threshold[4], int j)
{
  int retained = 0;
  for (k = 0; k < nb_match_blocks; k++)
    {
      const float thresh = threshold[(j == 0) + (i == 0) + (k == 0)];
      if (bufferz[k] > thresh || bufferz[k] < -thresh)
	{
	  retained++;
	}
      else
	{
	  bufferz[k] = 0;
	}
    }
}
