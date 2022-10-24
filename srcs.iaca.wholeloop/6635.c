#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int16_t basis[64][64], int i, int x, uint8_t * perm, int j)
{
  IACA_START for (x = 0; x < 8; x++)
    {
      double s = 0.25 * (1 << 16);
      int index = 8 * i + j;
      int perm_index = perm[index];
      if (i == 0)
	s *= sqrt (0.5);
      if (j == 0)
	s *= sqrt (0.5);
      basis[perm_index][8 * x + y] =
	lrintf (s * cos ((3.14159265358979323846 / 8.0) * i * (x + 0.5)) *
		cos ((3.14159265358979323846 / 8.0) * j * (y + 0.5)));
     } IACA_END
}
