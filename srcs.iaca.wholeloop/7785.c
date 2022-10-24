#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

int
fn (uint32_t occ[256], int i, uint32_t l2tab[256], int m, uint64_t len)
{
  IACA_START for (m = 1; m < 256; m++)
    if (occ[m])
      {
	len +=
	  (occ[m] *
	   ((i * (uint64_t) l2tab[m] +
	     (256 - i) * (uint64_t) l2tab[256 - m]) >> 8)) >> 8;
      }
  IACA_END
}
