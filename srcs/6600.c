#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef int32_t MPA_INT;

int
fn (MPA_INT * window, int i, const int32_t ff_mpa_enwindow[257])
{
  for (i = 0; i < 257; i++)
    {
      int v;
      v = ff_mpa_enwindow[i];
      window[i] = v;
      if ((i & 63) != 0)
	v = -v;
      if (i != 0)
	window[512 - i] = v;
    }
}
