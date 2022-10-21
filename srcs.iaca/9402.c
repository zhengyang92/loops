#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int x, int score, uint8_t * s)
{
  for (x = 0; x < 16; x += 4)
     { IACA_START
      score +=
	((s[x] - s[x + stride]) * (s[x] - s[x + stride])) +
	((s[x + 1] - s[x + stride + 1]) * (s[x + 1] - s[x + stride + 1])) +
	((s[x + 2] - s[x + stride + 2]) * (s[x + 2] - s[x + stride + 2])) +
	((s[x + 3] - s[x + stride + 3]) * (s[x + 3] - s[x + stride + 3]));
     } IACA_END
}
