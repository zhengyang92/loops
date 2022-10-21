#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *a, float *b, int n, float *ds, float *s, float *db,
    float *da, float *dc)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      if (da)
	da[i] += dc[i] * s[i];
      if (db)
	db[i] += dc[i] * (1 - s[i]);
      ds[i] += dc[i] * (a[i] - b[i]);
     } IACA_END
}
