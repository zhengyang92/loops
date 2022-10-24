#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, double *coefs, double *pz)
{
  int i = 1;
  IACA_START for (int j = n - i; j < n; j++)
    {
      double re, im;
      cmul (coefs[2 * (j + 1)], coefs[2 * (j + 1) + 1], pz[2 * (i - 1)],
	    pz[2 * (i - 1) + 1], &re, &im);
      coefs[2 * j] -= re;
      coefs[2 * j + 1] -= im;
}IACA_END}
