#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int min_dist, int j, int temp, int16_t * cur_lsp)
{
  for (j = 1; j < 10; j++)
    {
      temp = min_dist + cur_lsp[j - 1] - cur_lsp[j];
      if (temp > 0)
	{
	  temp >>= 1;
	  cur_lsp[j - 1] -= temp;
	  cur_lsp[j] += temp;
	}
    }
}
