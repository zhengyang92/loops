#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (double e, uint16_t * tbl)
{
  int i = 0;
  for (i = 0; i < 65536; ++i)
    {
      tbl[i] = pow (i / 65535.0, e) * 65535.0;
    }
}
