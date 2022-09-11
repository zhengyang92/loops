#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int len[512], int up[512], int i, uint8_t * dst)
{
  int size = 256;
  for (i = 0; i < size; i++)
    {
      dst[i] = len[up[i]] + 1;
      if (dst[i] >= 32)
	break;
    }
}
