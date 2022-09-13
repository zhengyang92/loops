#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, int i, uint8_t log8[256], uint8_t alog8[512])
{
  for (i = 0; i < 255; i++)
    {
      alog8[i] = alog8[i + 255] = j;
      log8[j] = i;
      j ^= j + j;
      if (j > 255)
	j ^= 0x11B;
    }
}
