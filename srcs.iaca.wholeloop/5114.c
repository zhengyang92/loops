#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef float MPA_INT;

int
fn (int i, MPA_INT * window, const int32_t ff_mpa_enwindow[257])
{
  IACA_START for (i = 0; i < 257; i++)
    {
      float v;
      v = ff_mpa_enwindow[i];
      v *= 1.0 / (1LL << (16 + 23));
      window[i] = v;
      if ((i & 63) != 0)
	v = -v;
      if (i != 0)
	window[512 - i] = v;
     } IACA_END
}
