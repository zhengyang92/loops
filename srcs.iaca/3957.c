#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (double rgbgammainv, int16_t xyzgammainv_tab[4096], int i,
    double xyzgammainv, int16_t rgbgammainv_tab[4096], double rgbgamma,
    int16_t rgbgamma_tab[4096], int16_t xyzgamma_tab[4096], double xyzgamma)
{
  for (i = 0; i < 4096; i++)
     { IACA_START
      xyzgamma_tab[i] = lrint (pow (i / 4095.0, xyzgamma) * 4095.0);
      rgbgamma_tab[i] = lrint (pow (i / 4095.0, rgbgamma) * 4095.0);
      xyzgammainv_tab[i] = lrint (pow (i / 4095.0, xyzgammainv) * 4095.0);
      rgbgammainv_tab[i] = lrint (pow (i / 4095.0, rgbgammainv) * 4095.0);
     } IACA_END
}
