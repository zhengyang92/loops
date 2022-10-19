#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t dwtcoef;
typedef long int ptrdiff_t;

int
fn (dwtcoef * linelh, int x, int width, dwtcoef * synthl, dwtcoef * linehl,
    dwtcoef * linehh, dwtcoef * linell, ptrdiff_t synthw)
{
  for (x = 0; x < width; x++)
    {
      linell[x] = synthl[(x << 1)];
      linehl[x] = synthl[(x << 1) + 1];
      linelh[x] = synthl[(x << 1) + synthw];
      linehh[x] = synthl[(x << 1) + synthw + 1];
    }
}
