#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, INT32 tmp0, INT32 tmp1, DCTELEM * dataptr, int ctr)
{
  IACA_START for (ctr = 0; ctr < 3; ctr++)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 2];
      tmp1 = dataptr[8 * 1];
      tmp2 = dataptr[8 * 0] - dataptr[8 * 2];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp0 +
		       tmp1) *
		      (((INT32)
			((1.777777778) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 2] =
	(DCTELEM) (((((tmp0 - tmp1 -
		       tmp1) *
		      (((INT32)
			((1.257078722) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 1] =
	(DCTELEM) (((((tmp2) *
		      (((INT32)
			((2.177324216) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr++;
     } IACA_END
}
