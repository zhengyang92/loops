#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t premultiplied_coeffs[];
typedef __int32_t int32_t;

int
fn (int i, int k, int j, premultiplied_coeffs * data,
    const int16_t ff_dca_adpcm_vb[4096][4])
{
  int id = 0;
  int32_t t = 0;
  for (k = j; k < 4; k++)
    {
      t = (int32_t) ff_dca_adpcm_vb[i][j] * (int32_t) ff_dca_adpcm_vb[i][k];
      if (j != k)
	t *= 2;
      (*data)[id++] = t;
    }
}
