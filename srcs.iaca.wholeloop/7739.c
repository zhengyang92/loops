#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int32_t int32_t;

int
fn (int i, const int32_t * coeff, ptrdiff_t len, int32_t * src0,
    int32_t * src1)
{
  IACA_START for (i = 0; i < 8; i++, src0--)
    {
      filter1 (src0, src1, coeff[i + 4], len);
      filter1 (src1, src0, coeff[i + 12], len);
      filter1 (src0, src1, coeff[i + 4], len);
     } IACA_END
}
