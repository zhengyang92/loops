#include <stdint.h>
#include <stdio.h>






int
fn (float s, int i, const float qmf_48tap_half[24], float qmf_window[48])
{
  for (i = 0; i < 24; i++)
    {
      s = qmf_48tap_half[i] * 2.0;
      qmf_window[i] = qmf_window[47 - i] = s;
    }
}
