#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int intptr_t;

int
fn (const float (*X_high)[40][2], const float *g_filt, int m, float (*Y)[2],
    int m_max, intptr_t ixh)
{
  for (m = 0; m < m_max; m++)
    {
      Y[m][0] = X_high[m][ixh][0] * g_filt[m];
      Y[m][1] = X_high[m][ixh][1] * g_filt[m];
    }
}
