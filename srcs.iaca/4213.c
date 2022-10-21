#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int w, unsigned int mbits, unsigned int x, const uint8_t * mask,
    int l2depth, unsigned int xmmod, unsigned int t, unsigned int xm,
    unsigned int mmult, unsigned int xmshf)
{
  for (x = 0; x < w; x++)
     { IACA_START
      t +=
	((mask[xm >> xmshf] >> ((~xm & xmmod) << l2depth)) & mbits) * mmult;
      xm++;
     } IACA_END
}
