#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * top, int arr1[16], int bottommost, int r6, int size, int shift)
{
  for (int x = 0; x < size; x++)
     { IACA_START
      int val = top[x];
      arr1[x] =
	adjust (((bottommost - val) * (1 << shift)) + r6 * (x + 1), size);
} IACA_END }
