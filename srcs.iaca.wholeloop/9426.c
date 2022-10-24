#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t MPA_INT;
typedef __int32_t int32_t;

int
fn (int i, MPA_INT * window, const int32_t ff_mpa_enwindow[257])
{
  IACA_START for (i = 0; i < 257; i++)
    {
      int v;
      v = ff_mpa_enwindow[i];
      window[i] = v;
      if ((i & 63) != 0)
	v = -v;
      if (i != 0)
	window[512 - i] = v;
     } IACA_END
}
