#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, int i)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      const int a0 = block[i + 0 * 8] + block[i + 4 * 8];
      const int a2 = block[i + 0 * 8] - block[i + 4 * 8];
      const int a4 = (block[i + 2 * 8] >> 1) - block[i + 6 * 8];
      const int a6 = (block[i + 6 * 8] >> 1) + block[i + 2 * 8];
      const int b0 = a0 + a6;
      const int b2 = a2 + a4;
      const int b4 = a2 - a4;
      const int b6 = a0 - a6;
      const int a1 =
	-block[i + 3 * 8] + block[i + 5 * 8] - block[i + 7 * 8] -
	(block[i + 7 * 8] >> 1);
      const int a3 =
	block[i + 1 * 8] + block[i + 7 * 8] - block[i + 3 * 8] -
	(block[i + 3 * 8] >> 1);
      const int a5 =
	-block[i + 1 * 8] + block[i + 7 * 8] + block[i + 5 * 8] +
	(block[i + 5 * 8] >> 1);
      const int a7 =
	block[i + 3 * 8] + block[i + 5 * 8] + block[i + 1 * 8] +
	(block[i + 1 * 8] >> 1);
      const int b1 = (a7 >> 2) + a1;
      const int b3 = a3 + (a5 >> 2);
      const int b5 = (a3 >> 2) - a5;
      const int b7 = a7 - (a1 >> 2);
      block[i + 0 * 8] = b0 + b7;
      block[i + 7 * 8] = b0 - b7;
      block[i + 1 * 8] = b2 + b5;
      block[i + 6 * 8] = b2 - b5;
      block[i + 2 * 8] = b4 + b3;
      block[i + 5 * 8] = b4 - b3;
      block[i + 3 * 8] = b6 + b1;
      block[i + 4 * 8] = b6 - b1;
} IACA_END }
