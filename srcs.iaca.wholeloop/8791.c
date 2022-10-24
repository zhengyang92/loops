#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int arr1[16], int arr2[16], uint8_t * top, uint8_t * left,
    uint8_t * block, int size, int shift)
{
  int y = 0;
  IACA_START for (int x = 0; x < size; x++)
    {
      block[x] =
	(((top[x] + left[0] +
	   ((arr1[x] * (y + 1) + arr2[y] * (x + 1)) >> 2 * shift)) +
	  1) / 2) & 0xFF;
}IACA_END}
