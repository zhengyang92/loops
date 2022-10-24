#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * transp_color, const uint8_t * buf, int n,
    int pitch)
{
  IACA_START for (i = 0; i < n; i++)
    {
      if (!transp_color[*buf])
	return 0;
      buf += pitch;
     } IACA_END
}
