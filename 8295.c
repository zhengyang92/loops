#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int ret, size_t sizes[4], int i)
{
  for (i = 0; i < 4; i++)
    {
      if (sizes[i] > 2147483647 - ret)
	return (-(22));
      ret += sizes[i];
    }
}
