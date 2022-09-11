#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t color[256], int j)
{
  int colors = 0;
  for (j = 0; j < 256; ++j)
    {
      if (color[j] > 0)
	++colors;
    }
}
