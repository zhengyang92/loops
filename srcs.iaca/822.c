#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * cmkp_tmp, int u, const int yhalf, const int cmk_linesize)
{
  int sum = 0;
  for (u = 0; u < yhalf; u++)
     { IACA_START
      if (cmkp_tmp[-cmk_linesize] == 0xff && cmkp_tmp[0] == 0xff
	  && cmkp_tmp[cmk_linesize] == 0xff)
	sum++;
      cmkp_tmp += cmk_linesize;
     } IACA_END
}
