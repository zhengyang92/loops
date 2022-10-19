#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * cmkp_tmp, const int yhalf, int u, const int cmk_linesize)
{
  int sum = 0;
  for (u = 0; u < yhalf; u++)
    {
      if (cmkp_tmp[-cmk_linesize] == 0xff && cmkp_tmp[0] == 0xff
	  && cmkp_tmp[cmk_linesize] == 0xff)
	sum++;
      cmkp_tmp += cmk_linesize;
    }
}
