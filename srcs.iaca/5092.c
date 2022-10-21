#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int arr1[16], uint8_t * top, int arr2[16], uint8_t * left,
    uint8_t * block, int size, int shift)
{
  int y = 0;
  for (int x = 0; x < size; x++)
     { IACA_START
      block[x] =
	(((top[x] + left[0] +
	   ((arr1[x] * (y + 1) + arr2[y] * (x + 1)) >> 2 * shift)) +
	  1) / 2) & 0xFF;
} IACA_END }
