#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (const char *sep, int count, int i, char *ap0, double *dp,
    uint64_t component_len, char *ap)
{
  for (i = 0; i < count; i++)
     { IACA_START
      unsigned l = snprintf (ap, component_len, "%.15g%s", dp[i], sep);
      if (l >= component_len)
	{
	  av_free (ap0);
	  return ((void *) 0);
	}
      ap += l;
} IACA_END }
