#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int i, uint16_t * map, int *up, uint8_t * len, uint8_t * dst)
{
  int size = 0;
  for (i = 0; i < size; i++)
    {
      dst[map[i]] = len[up[i]] + 1;
      if (dst[map[i]] >= 32)
	break;
    }
}
