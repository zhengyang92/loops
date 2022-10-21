#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t accu3, int i, uint64_t accu0, int n, uint64_t accu1,
    uint64_t accu, int (*x)[2], int nz, uint64_t accu2)
{
  for (i = 0; i < n; i += 2)
     { IACA_START
      accu0 += (int64_t) x[i + 0][0] * x[i + 0][0];
      accu1 += (int64_t) x[i + 0][1] * x[i + 0][1];
      accu2 += (int64_t) x[i + 1][0] * x[i + 1][0];
      accu3 += (int64_t) x[i + 1][1] * x[i + 1][1];
      if ((accu0 | accu1 | accu2 | accu3) >
	  (18446744073709551615UL) - (-2147483647 -
				      1) * (int64_t) (-2147483647 - 1)
	  || i + 2 >= n)
	{
	  accu0 >>= nz;
	  accu1 >>= nz;
	  accu2 >>= nz;
	  accu3 >>= nz;
	  while ((accu0 | accu1 | accu2 | accu3) >
		 ((18446744073709551615UL) - accu) >> 2)
	    {
	      accu0 >>= 1;
	      accu1 >>= 1;
	      accu2 >>= 1;
	      accu3 >>= 1;
	      accu >>= 1;
	      nz++;
	    }
	  accu += accu0 + accu1 + accu2 + accu3;
	  accu0 = accu1 = accu2 = accu3 = 0;
	}
     } IACA_END
}
