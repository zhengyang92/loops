#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int i, size_t sizes[4], int ret)
{
  for (i = 0; i < 4; i++)
    {
      if (sizes[i] > 2147483647 - ret)
	return (-(22));
      ret += sizes[i];
    }
}
