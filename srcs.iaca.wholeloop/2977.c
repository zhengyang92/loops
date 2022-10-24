#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint16_t uint16_t;

int
fn (int ylinesize, uint16_t * dsty, unsigned int control[4],
    GetBitContext bit, unsigned int y_min, unsigned int y_diff)
{
  int x = 0;
  IACA_START for (int i = 0; i < 4; i++)
    {
      const int nb_bits = control[i] + 1;
      const int div = (1 << nb_bits) - 1;
      const int add = div - 1;
      dsty[x + i * ylinesize + 0] =
	av_clip_uintp2_c (y_min +
			  ((y_diff * get_bits (&bit, nb_bits) + add) / div),
			  12);
      dsty[x + i * ylinesize + 1] =
	av_clip_uintp2_c (y_min +
			  ((y_diff * get_bits (&bit, nb_bits) + add) / div),
			  12);
      dsty[x + i * ylinesize + 2] =
	av_clip_uintp2_c (y_min +
			  ((y_diff * get_bits (&bit, nb_bits) + add) / div),
			  12);
      dsty[x + i * ylinesize + 3] =
	av_clip_uintp2_c (y_min +
			  ((y_diff * get_bits (&bit, nb_bits) + add) / div),
			  12);
}IACA_END}
