#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * buf, int16_t * lpc_ptr, int16_t * autocorr_ptr, int j)
{
  for (i = 0, j = 0; j < 4; i += 60, j++)
    {
      comp_autocorr (buf + i, autocorr_ptr);
      levinson_durbin (lpc_ptr, autocorr_ptr + 1, autocorr_ptr[0]);
      lpc_ptr += 10;
      autocorr_ptr += 10 + 1;
    }
}
