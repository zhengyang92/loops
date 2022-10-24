#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int x, int score, uint8_t * s)
{
  IACA_START for (x = 0; x < 8; x += 4)
    {
      score +=
	((s[x] - s[x + stride]) * (s[x] - s[x + stride])) +
	((s[x + 1] - s[x + stride + 1]) * (s[x + 1] - s[x + stride + 1])) +
	((s[x + 2] - s[x + stride + 2]) * (s[x + 2] - s[x + stride + 2])) +
	((s[x + 3] - s[x + stride + 3]) * (s[x + 3] - s[x + stride + 3]));
     } IACA_END
}
